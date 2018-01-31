[1mdiff --git a/CRM/CivirulesConditions/Form/FieldValueChangeComparison.php b/CRM/CivirulesConditions/Form/FieldValueChangeComparison.php[m
[1mindex 0636223..333a409 100644[m
[1m--- a/CRM/CivirulesConditions/Form/FieldValueChangeComparison.php[m
[1m+++ b/CRM/CivirulesConditions/Form/FieldValueChangeComparison.php[m
[36m@@ -165,7 +165,7 @@[m [mclass CRM_CivirulesConditions_Form_FieldValueChangeComparison extends CRM_Civiru[m
     if (isset($this->_submitValues['multi_value'])) {[m
       $data['multi_value'] = explode("\r\n", $this->_submitValues['multi_value']);[m
     }[m
[31m-[m
[32m+[m[41m    [m
     $this->ruleCondition->condition_params = serialize($data);[m
     $this->ruleCondition->save();[m
 [m
[1mdiff --git a/CRM/CivirulesConditions/Generic/FieldValueChangeComparison.php b/CRM/CivirulesConditions/Generic/FieldValueChangeComparison.php[m
[1mindex 52ccb4e..34c5b89 100644[m
[1m--- a/CRM/CivirulesConditions/Generic/FieldValueChangeComparison.php[m
[1m+++ b/CRM/CivirulesConditions/Generic/FieldValueChangeComparison.php[m
[36m@@ -148,7 +148,7 @@[m [mabstract class CRM_CivirulesConditions_Generic_FieldValueChangeComparison extend[m
     $value = $this->getFieldValue($triggerData);[m
     $compareValue = $this->getComparisonValue();[m
     $newComparison = $this->compare($value, $compareValue, $this->getOperator());[m
[31m-[m
[32m+[m[41m		[m
     if ($originalComparison && $newComparison) {[m
       return true;[m
     }[m
[36m@@ -167,11 +167,31 @@[m [mabstract class CRM_CivirulesConditions_Generic_FieldValueChangeComparison extend[m
    * @access public[m
    */[m
   public function userFriendlyConditionParams() {[m
[32m+[m[41m  [m	[32m$options = $this->getFieldOptions();[m
     $originalComparisonValue = $this->getOriginalComparisonValue();[m
[32m+[m		[32m$comparisonValue = $this->getComparisonValue();[m
[32m+[m		[32mif (is_array($options)) {[m
[32m+[m			[32mif (is_array($originalComparisonValue)) {[m
[32m+[m				[32mforeach($originalComparisonValue as $index => $originalComparisonValueKey) {[m
[32m+[m					[32m$originalComparisonValue[$index] = $options[$originalComparisonValueKey];[m
[32m+[m				[32m}[m
[32m+[m			[32m} else {[m
[32m+[m				[32m$originalComparisonValue = $options[$originalComparisonValue];[m
[32m+[m			[32m}[m
[32m+[m[41m			[m
[32m+[m			[32mif (is_array($comparisonValue)) {[m
[32m+[m				[32mforeach($comparisonValue as $index => $comparisonValueKey) {[m
[32m+[m					[32m$comparisonValue[$index] = $options[$comparisonValueKey];[m
[32m+[m				[32m}[m
[32m+[m			[32m} else {[m
[32m+[m				[32m$comparisonValue = $options[$comparisonValue];[m
[32m+[m			[32m}[m
[32m+[m		[32m}[m
[32m+[m[41m    [m
     if (is_array($originalComparisonValue)) {[m
       $originalComparisonValue = implode(", ", $originalComparisonValue);[m
     }[m
[31m-    $comparisonValue = $this->getComparisonValue();[m
[32m+[m[41m    [m
     if (is_array($comparisonValue)) {[m
       $comparisonValue = implode(", ", $comparisonValue);[m
     }[m
[1mdiff --git a/info.xml b/info.xml[m
[1mindex d083089..a0bdc1e 100644[m
[1m--- a/info.xml[m
[1m+++ b/info.xml[m
[36m@@ -14,8 +14,8 @@[m
     <author>CiviCooP</author>[m
     <email>helpdesk@civicoop.org</email>[m
   </maintainer>[m
[31m-  <releaseDate>2017-11-13</releaseDate>[m
[31m-  <version>1.15</version>[m
[32m+[m[32m  <releaseDate>2018-01-18</releaseDate>[m
[32m+[m[32m  <version>1.16</version>[m
   <develStage>stable</develStage>[m
   <compatibility>[m
     <ver>4.4</ver>[m
[1mdiff --git a/templates/CRM/CivirulesConditions/Form/FieldValueChangeComparison.tpl b/templates/CRM/CivirulesConditions/Form/FieldValueChangeComparison.tpl[m
[1mindex 5c12f42..578989e 100644[m
[1m--- a/templates/CRM/CivirulesConditions/Form/FieldValueChangeComparison.tpl[m
[1m+++ b/templates/CRM/CivirulesConditions/Form/FieldValueChangeComparison.tpl[m
[36m@@ -177,7 +177,7 @@[m
             cj('#original_value_options').removeClass('hiddenElement');[m
             cj('#original_value_options').change(function() {[m
                 var value = cj(this).val();[m
[31m-                cj('#value').val(value);[m
[32m+[m[32m                cj('#original_value').val(value);[m
             });[m
 [m
             cj('#original_multi_value').val(selectedOptions.join('\r\n'));[m
