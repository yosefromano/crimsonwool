<div class="crm-content-block crm-block">
  <div id="help">
    The existing CiviRules are listed below. You can manage, delete, disable/enable or add a rule. 
  </div>
  <div class="action-link">
    <a class="button new-option" href="{$add_url}">
      <span><div class="icon add-icon ui-icon-circle-plus"></div>{ts}Add CiviRule{/ts}</span>
    </a>
  </div>
  <div id="civirule_wrapper" class="dataTables_wrapper">
    <table id="civirule-table" class="display">
      <thead>
        <tr>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Name{/ts}</th>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Trigger{/ts}</th>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Active{/ts}</th>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Description{/ts}</th>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Date Created{/ts}</th>
          <th class="sorting-disabled" rowspan="1" colspan="1">{ts}Created By{/ts}</th>
          <th class="sorting_disabled" rowspan="1" colspan="1"></th>
        </tr>
      </thead>
      <tbody>
        {assign var="row_class" value="odd-row"}
        {foreach from=$rules key=rule_id item=rule}
          <tr id="row_{$rule.id}" class={$row_class}>
            <td hidden="1">{$rule.id}</td>
            <td>{$rule.label}</td>
            <td>{$rule.trigger_label}</td>
            <td>{$rule.is_active}</td>
            <td>{$rule.description}
              {if (!empty($rule.help_text))}
                {if $earlier_than_46 eq 0}
                  <a class="crm-popup medium-popup helpicon" href="{crmURL p='civicrm/civirules/civirulehelptext' q="reset=1&rid=`$rule.id`"}"></a>
                {else}
                  <a class="crm-popup medium-popup helpicon" href="{crmURL p='civicrm/civirules/civirulehelptext44' q="reset=1&rid=`$rule.id`"}"></a>
                {/if}
              {/if}
            </td>
            <td>{$rule.created_date|crmDate}</td>
            <td>{$rule.created_contact_name}</td>
            <td>
              <span>
                {foreach from=$rule.actions item=action_link}
                  {$action_link}
                {/foreach}
              </span>
            </td>
          </tr>
          {if $row_class eq "odd-row"}
            {assign var="row_class" value="even-row"}
          {else}
            {assign var="row_class" value="odd-row"}                        
          {/if}
        {/foreach}
      </tbody>
    </table>    
  </div>
  <div class="action-link">
    <a class="button new-option" href="{$add_url}">
      <span><div class="icon add-icon ui-icon-circle-plus"></div>{ts}Add CiviRule{/ts}</span>
    </a>
  </div>
</div>

{literal}
  <script type="text/javascript">
    function showRuleHelp(ruleId, helpText) {
      if (helpText) {
        CRM.alert(helpText, 'CiviRule Help', 'info');
      } else {
        CRM.alert('There is no help text defined for this rule. You can set the help text when you edit the rule', 'No Help for CiviRule', 'info');
      }
    }
  </script>
{/literal}


