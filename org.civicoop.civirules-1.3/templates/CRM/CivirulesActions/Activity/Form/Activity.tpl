<h3>{$ruleActionHeader}</h3>
<div class="crm-block crm-form-block crm-civirule-rule_action-block-activity">
    <div class="crm-section">
        <div class="label">{$form.activity_type_id.label}</div>
        <div class="content">{$form.activity_type_id.html}</div>
        <div class="clear"></div>
    </div>
    <div class="crm-section">
        <div class="label">{$form.status_id.label}</div>
        <div class="content">{$form.status_id.html}</div>
        <div class="clear"></div>
    </div>
    <div class="crm-section">
        <div class="label">{$form.subject.label}</div>
        <div class="content">{$form.subject.html}</div>
        <div class="clear"></div>
    </div>

    {if ($use_old_contact_ref_fields)}
        <div class="crm-section">
            <div class="label">{ts}Assignee{/ts}</div>
            <div class="content">
                {include file="CRM/Contact/Form/NewContact.tpl" noLabel=true skipBreak=true multiClient=false showNewSelect=false contact_id=$assignee_contact_id}
            </div>
            <div class="clear"></div>
        </div>
    {else}
        <div class="crm-section">
            <div class="label">{$form.assignee_contact_id.label}</div>
            <div class="content">{$form.assignee_contact_id.html}</div>
            <div class="clear"></div>
        </div>
    {/if}
    <div class="crm-section">
        <div class="label">{$form.activity_date_time.label}</div>
        <div class="content">{$form.activity_date_time.html}</div>
        <div class="clear"></div>
    </div>
    {foreach from=$delayClasses item=delayClass}
        <div class="crm-section crm-activity_date_time-class" id="{$delayClass->getName()}">
            <div class="label"></div>
            <div class="content"><strong>{$delayClass->getDescription()}</strong></div>
            <div class="clear"></div>
            {include file=$delayClass->getTemplateFilename() delayPrefix='activity_date_time'}
        </div>
    {/foreach}
</div>
<div class="crm-submit-buttons">
    {include file="CRM/common/formButtons.tpl" location="bottom"}
</div>

{literal}
    <script type="text/javascript">
        cj(function() {
            cj('select#activity_date_time').change(triggerDelayChange);

            triggerDelayChange();
        });

        function triggerDelayChange() {
            cj('.crm-activity_date_time-class').css('display', 'none');
            var val = cj('#activity_date_time').val();
            if (val) {
                cj('#'+val).css('display', 'block');
            }
        }
    </script>
{/literal}