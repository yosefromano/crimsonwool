<h3>{$ruleConditionHeader}</h3>
<div class="crm-block crm-form-block crm-civirule-rule_condition-block-has_activity_in_campaign">
  <div class="crm-section sector-section">
    <div class="label">
      <label for="activity_type-select">{$form.activity_type_id.label}</label>
    </div>
    <div class="content crm-select-container" id="activity_type_block">
      {$form.activity_type_id.html}
    </div>
    <div class="clear"></div>
  </div>
  <div class="crm-section sector-section">
    <div class="label">
      <label for="campaign-select">{$form.campaign_id.label}</label>
    </div>
    <div class="content crm-select-container" id="campaign_block">
      {$form.campaign_id.html}
    </div>
    <div class="clear"></div>
  </div>
</div>
<div class="crm-submit-buttons">
  {include file="CRM/common/formButtons.tpl" location="bottom"}
</div>