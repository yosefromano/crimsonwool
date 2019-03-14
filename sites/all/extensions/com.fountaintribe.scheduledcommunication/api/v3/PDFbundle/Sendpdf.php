<?php

/**
 * PDFbundle.Sendpdf API specification (optional)
 * This is used for documentation and validation.
 *
 * @param array $spec description of fields supported by this API call
 * @return void
 * @see http://wiki.civicrm.org/confluence/display/CRM/API+Architecture+Standards
 */
function _civicrm_api3_p_d_fbundle_Sendpdf_spec(&$spec) {
	$spec['group']['api.required'] = 1;
	$spec['message_template']['api.required'] = 1;
	$spec['staff_contact']['api.required'] = 1;
	
}

/**
 * PDFbundle.Sendpdf API
 *
 * @param array $params
 * @return array API result descriptor
 * @see civicrm_api3_create_success
 * @see civicrm_api3_create_error
 * @throws API_Exception
 */
function civicrm_api3_p_d_fbundle_Sendpdf($params) {
	if (array_key_exists('group', $params) && strlen($params['group']) > 0
			&& array_key_exists('message_template', $params) && strlen($params['message_template']) > 0
			&& array_key_exists('staff_contact', $params) && strlen($params['staff_contact']) > 0 ) {
					
				$tmp_group_title = $params['group'];
				$tmp_template_title = $params['message_template'];
				$tmp_staff_contact = $params['staff_contact'];
				$tmp_grp_id = "";
				$contacts_in_pdf= 0;
				$pdf_result = "";
								
	
			
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
				
				 */
				$result = civicrm_api('contact', 'get', array(
						'version' => 3,
						'group' => array($tmp_grp_id => 1),
						'options' => array('limit' => 0),
				));
					
				// loop through each, and add pages to the big PDF file for each contact.
				if( $result['is_error'] == 0 && $result['count'] > 0){
					$values = $result['values'];
	
					foreach($values as $cur_contact ){
						$cur_con_id = $cur_contact['contact_id'];
							
						//  add this contact's message to the big PDF file.
					
							
							
						if( $pdf_result['is_error'] == 0){
							
							$contacts_in_pdf += 1;
						}else{

							$emails_send_failure[] = $cur_con_id;
						}
	
								
						
							
							
					}
	
				}else if( $result['is_error'] <> 0){
					throw new API_Exception(/*errorMessage*/ "API failure when attempting to get contacts in the group '".$tmp_group_title."'" , /*errorCode*/ 1234);
				}
					
				
				// finished with all contacts in the group. Now create the big PDF file from $html
				$fileName = CRM_Utils_String::munge($messageTemplates->msg_title) . '.pdf';
				$pdf = CRM_Utils_PDF_Utils::html2pdf($html, $fileName, TRUE, $messageTemplates->pdf_format_id);
				$tmpFileName = CRM_Utils_File::tempnam();
				file_put_contents($tmpFileName, $pdf);
				unset($pdf); //we don't need the temp file in memory
				
				
				
				
				//send PDF to the staff email address.
				$from = CRM_Core_BAO_Domain::getNameAndEmail();
				$from = "$from[0] <$from[1]>";
				// set up the parameters for CRM_Utils_Mail::send
				$mailParams = array(
						'groupName' => 'PDF Letter API',
						'from' => $from,
						'toName' => $from[0],
						'toEmail' => $params['to_email'],
						'subject' => 'PDF Letter from CiviCRM - ' . $messageTemplates->msg_title,
						'text' => "CiviCRM has generated a PDF letter",
						'attachments' => array(
								array(
										'fullPath' => $tmpFileName,
										'mime_type' => 'application/pdf',
										'cleanName' => $fileName,
								)
						)
				);
				$result = CRM_Utils_Mail::send($mailParams);
				if (!$result) {
					throw new API_Exception('Error sending e-mail to '.$params['to_email']);
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
			
			
			function create_pdf_file(){
				
				$domain  = CRM_Core_BAO_Domain::getDomain();
				$version = CRM_Core_BAO_Domain::version();
				$html    = array();
				if (!preg_match('/[0-9]+(,[0-9]+)*/i', $params['contact_id'])) {
					throw new API_Exception('Parameter contact_id must be a unique id or a list of ids separated by comma');
				}
				$contactIds = explode(",", $params['contact_id']);
				// Compatibility with CiviCRM > 4.3
				if($version >= 4.4) {
					$messageTemplates = new CRM_Core_DAO_MessageTemplate();
				} else {
					$messageTemplates = new CRM_Core_DAO_MessageTemplates();
				}
				$messageTemplates->id = $params['template_id'];
				if (!$messageTemplates->find(TRUE)) {
					throw new API_Exception('Could not find template with ID: ' . $params['template_id']);
				}
				// Optional pdf_format_id, if not default 0
				if (isset($params['pdf_format_id'])) {
					$messageTemplates->pdf_format_id = CRM_Utils_Array::value('pdf_format_id', $params, 0);
				}
				$subject = $messageTemplates->msg_subject;
				$html_template = _civicrm_api3_pdf_formatMessage($messageTemplates);
				$tokens = CRM_Utils_Token::getTokens($html_template);
				// get replacement text for these tokens
				$returnProperties = array(
						'sort_name' => 1,
						'email' => 1,
						'address' => 1,
						'do_not_email' => 1,
						'is_deceased' => 1,
						'on_hold' => 1,
						'display_name' => 1,
				);
				if (isset($messageToken['contact'])) {
					foreach ($messageToken['contact'] as $key => $value) {
						$returnProperties[$value] = 1;
					}
				}
				foreach($contactIds as $contactId){
					$html_message = $html_template;
					list($details) = CRM_Utils_Token::getTokenDetails(array($contactId), $returnProperties, false, false, null, $tokens);
					$contact = reset( $details );
					if (isset($contact['do_not_mail']) && $contact['do_not_mail'] == TRUE) {
						if(count($contactIds) == 1)
							throw new API_Exception('Suppressed creating pdf letter for: '.$contact['display_name'].' because DO NOT MAIL is set');
							else
								continue;
					}
					if (isset($contact['is_deceased']) && $contact['is_deceased'] == TRUE) {
						if(count($contactIds) == 1)
							throw new API_Exception('Suppressed creating pdf letter for: '.$contact['display_name'].' because contact is deceased');
							else
								continue;
					}
					if (isset($contact['on_hold']) && $contact['on_hold'] == TRUE) {
						if(count($contactIds) == 1)
							throw new API_Exception('Suppressed creating pdf letter for: '.$contact['display_name'].' because contact is on hold');
							else
								continue;
					}
					// call token hook
					$hookTokens = array();
					CRM_Utils_Hook::tokens($hookTokens);
					$categories = array_keys($hookTokens);
					CRM_Utils_Token::replaceGreetingTokens($html_message, NULL, $contact['contact_id']);
					$html_message = CRM_Utils_Token::replaceDomainTokens($html_message, $domain, true, $tokens, true);
					$html_message = CRM_Utils_Token::replaceContactTokens($html_message, $contact, false, $tokens, false, true);
					$html_message = CRM_Utils_Token::replaceComponentTokens($html_message, $contact, $tokens, true);
					$html_message = CRM_Utils_Token::replaceHookTokens($html_message, $contact , $categories, true);
					if (defined('CIVICRM_MAIL_SMARTY') && CIVICRM_MAIL_SMARTY) {
						$smarty = CRM_Core_Smarty::singleton();
						// also add the contact tokens to the template
						$smarty->assign_by_ref('contact', $contact);
						$html_message = $smarty->fetch("string:$html_message");
					}
					$html[] = $html_message;
					//create activity
					$activityTypeID = CRM_Core_OptionGroup::getValue('activity_type',
							'Print PDF Letter',
							'name'
							);
					$activityParams = array(
							'source_contact_id' => $contactId,
							'activity_type_id' => $activityTypeID,
							'activity_date_time' => date('YmdHis'),
							'details' => $html_message,
							'subject' => $subject,
					);
					$activity = CRM_Activity_BAO_Activity::create($activityParams);
					// Compatibility with CiviCRM >= 4.4
					if($version >= 4.4){
						$activityContacts = CRM_Core_OptionGroup::values('activity_contacts', FALSE, FALSE, FALSE, NULL, 'name');
						$targetID = CRM_Utils_Array::key('Activity Targets', $activityContacts);
						$activityTargetParams = array(
								'activity_id' => $activity->id,
								'contact_id' => $contactId,
								'record_type_id' => $targetID
						);
						CRM_Activity_BAO_ActivityContact::create($activityTargetParams);
					}
					else{
						$activityTargetParams = array(
								'activity_id' => $activity->id,
								'target_contact_id' => $contactId,
						);
						CRM_Activity_BAO_Activity::createActivityTarget($activityTargetParams);
					}
				}
				$fileName = CRM_Utils_String::munge($messageTemplates->msg_title) . '.pdf';
				$pdf = CRM_Utils_PDF_Utils::html2pdf($html, $fileName, TRUE, $messageTemplates->pdf_format_id);
				$tmpFileName = CRM_Utils_File::tempnam();
				file_put_contents($tmpFileName, $pdf);
				unset($pdf); //we don't need the temp file in memory
				
				$returnValues = array();
				return civicrm_api3_create_success($returnValues, $params, 'Pdf', 'Create');
				
				
			
			}
}

