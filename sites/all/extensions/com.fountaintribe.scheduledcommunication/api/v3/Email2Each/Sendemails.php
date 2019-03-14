<?php

/**
 * Email2Each.Sendemails API specification (optional)
 * This is used for documentation and validation.
 *
 * @param array $spec description of fields supported by this API call
 * @return void
 * @see http://wiki.civicrm.org/confluence/display/CRM/API+Architecture+Standards
 */
function _civicrm_api3_email2_each_Sendemails_spec(&$spec) {
  $spec['group']['api.required'] = 1;
  $spec['message_template']['api.required'] = 1;
}

/**
 * Email2Each.Sendemails API
 *
 * @param array $params
 * @return array API result descriptor
 * @see civicrm_api3_create_success
 * @see civicrm_api3_create_error
 * @throws API_Exception
 */
function civicrm_api3_email2_each_Sendemails($params) {
  if (array_key_exists('group', $params) && strlen($params['group']) > 0 
  		&& array_key_exists('message_template', $params) && strlen($params['message_template']) > 0 ) {
  			
  			$tmp_group_title = $params['group'];
  			$tmp_template_title = $params['message_template'];
  			$tmp_grp_id = "";
  			$emails_sent = 0;
  			$email_result = "";
  			$contacts_without_emails = array(); 
  			$emails_sent_to = array();
  			$emails_send_failure = array();
  			
  		
  			$email_ext_key =  "org.civicoop.emailapi"; 
  			$email_ext_url = "https://civicrm.org/extensions/e-mail-api";
  			
  			
  			// Check if needed extension that contains email API is installed and enabled.
  			$result = civicrm_api3('Extension', 'get', array(
  					'sequential' => 1,
  					'key' => $email_ext_key,
  					'is_active' => 1,
  			));
  			
  			// CRM_Core_Error::debug("Extension API call: ", $result);
  			
  			if( $result['count'] <> 1){
  				throw new API_Exception(/*errorMessage*/ "Missing required extension, extension key= '".$email_ext_key."' Get this extension at:  ".$email_ext_url, /*errorCode*/ 1234);
  				
  			}
  			
  			// check if group exists.
  			$result = civicrm_api3('Group', 'get', array(
  					'sequential' => 1,
  					'title' => $tmp_group_title,
  					'is_active' => 1, 
  					'is_hidden' => 0, 
  			));
  			if( $result['is_error'] == 0 && $result['count'] == 1){
  				$tmp_grp_id = $result['id'];
  			}else{
  				throw new API_Exception(/*errorMessage*/ "Could not find group titled '".$tmp_group_title."'" , /*errorCode*/ 1234);
  			}
  			
  			// check if template exists.
  			$result = civicrm_api3('MessageTemplate', 'get', array(
			  'sequential' => 1,
			  'msg_title' => $tmp_template_title,
  			  'is_active' => 1,
			));
  		
  			if( $result['is_error'] == 0 && $result['count'] == 1){
  				$tmp_template_id = $result['id'];
  			}else{
  				throw new API_Exception(/*errorMessage*/ "Could not find mesage template titled '".$tmp_template_title."'" , /*errorCode*/ 1234);
  			}
  						
  		//	CRM_Core_Error::debug("Group id: ", $tmp_grp_id); 
  			// get all contacts in the group.
  			/*
  			 * GroupContact does not deal with smart groups or nested groups/
  			 $result = civicrm_api3('GroupContact', 'get', array(
  					'sequential' => 1,
  					'group_id' => $tmp_grp_id,
  			));
  			*/
  			$result = civicrm_api('contact', 'get', array(
  					'version' => 3,
  					'group' => array($tmp_grp_id => 1),
  					'options' => array('limit' => 0),
  			));
  			
  			// loop through each, and send 1 email per contact. 
  			if( $result['is_error'] == 0 && $result['count'] > 0){
  				$values = $result['values'];
  				
  				foreach($values as $cur_contact ){
  					$cur_con_id = $cur_contact['contact_id'];
  					
  					
  					// get primary email address for this contact.(cannot be 'on_hold')
  					$em_address_result = civicrm_api3('Email', 'get', array(
  							'sequential' => 1,
  							'contact_id' => $cur_con_id,
  							'is_primary' => 1,
  							'on_hold' => 0,
  					));
  					
  					if( $em_address_result['is_error'] == 0 && $em_address_result['count'] > 0){
  					  $em_values = $em_address_result['values'];
  					  $cur_email_address = $em_values[0]['email'];
  					 
  					  
  					//  CRM_Core_Error::debug( "id: ".$cur_con_id, $cur_email_address);
  					 
  					  
  					  //  Send email.
  					  $send_result = civicrm_api3('Email', 'send', array(
  					  		'sequential' => 1,
  					  		'contact_id' => $cur_con_id,
  					  		'template_id' => $tmp_template_id,
  					  ));
  					  
  					  
  					  if( $send_result['is_error'] == 0){
  					 	 $emails_sent_to[] = $cur_con_id; 
  					  
  						//  $emails_sent_to[$cur_con_id] = $cur_email_address;
  					  	$emails_sent += 1;
  					  }else{
  					  	
  					  	$emails_send_failure[] = $cur_con_id; 
  					  }
  					 
  					
  					}else{
  						$contacts_without_emails[] = $cur_con_id;
  					}
  					
  					
  					
  				}
  				
  			}else if( $result['is_error'] <> 0){
  				throw new API_Exception(/*errorMessage*/ "API failure when attempting to get contacts in the group '".$tmp_group_title."'" , /*errorCode*/ 1234);
  			}
  			
  			
  		$tmp_without_email_str = implode(", ", $contacts_without_emails);
  		
  		$tmp_emails_send_to_str = implode(",",  $emails_sent_to);
  		
  		$tmp_send_failures_str = implode( ",", $emails_send_failure);
  	//	CRM_Core_Error::debug( "Contacts with a send failure: ", $emails_send_failure);
  		
    $returnValues = array( // OK, return several data rows
      $email_result => array('id' => 'email_sent_count', 'name' => $emails_sent),
    		34 => array( 'id' => 'contacts_missing_emails', 'name' => $tmp_without_email_str  ),
    		35 => array('id' => 'contacts_sending_failure', 'name' => $tmp_send_failures_str ),
    		36 =>  array( 'id' => 'emails_sent_to', 'name' => $tmp_emails_send_to_str  ),
    );
    
    /*
     * $returnValues = array( // OK, return several data rows
      $email_result => array('id' => 'email_result', 'name' => $emails_sent),
      34 => array('id' => 34, 'name' => 'Thirty four'),
      56 => array('id' => 56, 'name' => 'Fifty six'),
    );
     */
    // ALTERNATIVE: $returnValues = array(); // OK, success
    // ALTERNATIVE: $returnValues = array("Some value"); // OK, return a single value

    // Spec: civicrm_api3_create_success($values = 1, $params = array(), $entity = NULL, $action = NULL)
    return civicrm_api3_create_success($returnValues, $params, 'NewEntity', 'NewAction');
  } else {
    throw new API_Exception(/*errorMessage*/ 'Everyone knows that the magicword is "sesame"', /*errorCode*/ 1234);
  }
}

