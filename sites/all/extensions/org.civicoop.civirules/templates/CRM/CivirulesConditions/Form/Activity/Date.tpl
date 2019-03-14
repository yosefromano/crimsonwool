<h3>{$ruleConditionHeader}</h3>
<div class="crm-block crm-form-block crm-civirule-rule_condition-block-activity_date">
  <div class="crm-section">
    <div class="label">{$form.operator.label}</div>
    <div class="content operator">{$form.operator.html}</div>
    <div class="clear"></div>
  </div>
  <div class="crm-section sector-section activity-compare-date">
    <div class="label">{$form.activity_compare_date.label}</div>
    <div class="content activity-date-comparison">{$form.activity_compare_date.html}</div>
    <div class="clear"></div>
  </div>
  <div class="crm-section sector-section activity-from-date">
    <div class="label">{$form.activity_from_date.label}</div>
    <div class="content activity-date-from">{$form.activity_from_date.html}</div>
    <div class="clear"></div>
  </div>
  <div class="crm-section sector-section activity-to-date">
    <div class="label">{$form.activity_to_date.label}</div>
    <div class="content activity-date-to">{$form.activity_to_date.html}</div>
    <div class="clear"></div>
  </div>
</div>
<div class="crm-submit-buttons">
  {include file="CRM/common/formButtons.tpl" location="bottom"}
</div>
{literal}
  <script type="text/javascript">
    cj(document).ready(function() {
      var selectedOperator = cj('.operator').find(":selected").text();
      if (selectedOperator === 'between') {
        cj('.activity-compare-date').hide();
      }
      else {
        cj('.activity-from-date').hide();
        cj('.activity-to-date').hide();
      }
    });
    function checkOperator() {
      var selectedOperator = cj('.operator').find(":selected").text();
      if (selectedOperator === 'between') {
        cj('.activity-compare-date').hide();
        cj('.activity-from-date').show();
        cj('.activity-to-date').show();
      }
      else {
        cj('.activity-from-date').hide();
        cj('.activity-to-date').hide();
        cj('.activity-compare-date').show();
      }
    }
  </script>
{/literal}