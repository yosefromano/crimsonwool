{*
{* View Rule HelpText Window *}
<div class="crm-block crm-content-block crm-civirule-helptext-view-block">
  <table class="crm-info-panel" id="civirule-helptext-view-table">
    <tr class="crm-helptext-view">
      <td class="label">{$form.help_text.label}</td>
      <td>{$form.help_text.value}</td>
    </tr>
  </table>
  <div class="crm-submit-buttons">
    {crmButton p='civicrm/civirules/page/rule' q="reset=1" class='cancel' icon='close'}{ts}Done{/ts}{/crmButton}
  </div>
</div>
