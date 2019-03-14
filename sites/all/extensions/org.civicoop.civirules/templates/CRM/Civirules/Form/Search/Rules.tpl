{* Template for "FindExpert" custom search component. *}
{assign var="showBlock" value="'searchForm'"}
{assign var="hideBlock" value="'searchForm_show','searchForm_hide'"}

{* dialog for rule help text *}
<div id="civirule_helptext_dialog-block">
  <p><label id="civirule_help_text-value"></label></p>
</div>

{include file="CRM/Civirules/Form/Search/RulesCriteria.tpl"}

{if $rowsEmpty}
    {include file="CRM/Contact/Form/Search/Custom/EmptyResults.tpl"}
{/if}

{if $summary}
    {$summary.summary}: {$summary.total}
{/if}

{if $rows}
    {* Search request has returned 1 or more matching rows. Display results and collapse the search criteria fieldset. *}
    {assign var="showBlock" value="'searchForm_show'"}
    {assign var="hideBlock" value="'searchForm'"}

    <fieldset>

        {* This section displays the rows along and includes the paging controls *}
        <p>

            {include file="CRM/common/pager.tpl" location="top"}

            {include file="CRM/common/pagerAToZ.tpl"}

            {strip}
        <table class="selector" summary="{ts}Search results listings.{/ts}">
            <thead class="sticky">
            {foreach from=$columnHeaders item=header}
                <th scope="col">
                    {if $header.sort}
                        {if $header.name ne "RuleID" and $header.name ne "Hidden Active" and $header.name ne "Help Text"}
                            {assign var='key' value=$header.sort}
                            {$sort->_response.$key.link}
                        {/if}
                    {else}
                        {$header.name}
                    {/if}
                </th>
            {/foreach}
            <th>&nbsp;</th>
            </thead>

            {counter start=0 skip=1 print=false}
            {foreach from=$rows item=row}
                <tr id='rowid{$row.contact_id}' class="{cycle values="odd-row,even-row"}">
                    {foreach from=$columnHeaders item=header}
                        {assign var=fName value=$header.sort}
                        {if $fName ne 'rule_id' and $fName ne 'rule_is_active' and $fName ne 'rule_help_text'}
                            {if $fName eq 'rule_created_date'}
                                <td>{$row.$fName|crmDate}</td>
                            {else}
                                <td>
                                    {$row.$fName}
                                    {if $fName eq 'rule_description' and (!empty($row.rule_help_text))}
                                      <a id="civirule_help_text_icon" class="crm-popup medium-popup helpicon" onclick="showRuleHelp({$row.rule_id})" href="#"></a>
                                    {/if}
                                </td>

                            {/if}
                        {/if}
                    {/foreach}
                    <td><span><a href="{crmURL p='civicrm/civirule/form/rule' q="reset=1&action=update&id=`$row.rule_id`"}"
                        class="action-item action-item-first" title="Edit Rule">Edit</a></span></td>
                    {if $row.rule_is_active eq 1}
                        <td><span><a href="{crmURL p='civicrm/civirule/form/rule' q="reset=1&action=disable&id=`$row.rule_id`"}"
                            class="action-item action-item-first" title="Disable Rule">Disable</a></span></td>
                    {else}
                        <td><span><a href="{crmURL p='civicrm/civirule/form/rule' q="reset=1&action=enable&id=`$row.rule_id`"}"
                             class="action-item action-item-first" title="Enable Rule">Enable</a></span></td>
                    {/if}
                    <td><span><a href="{crmURL p='civicrm/civirule/form/ruledelete' q="reset=1&action=delete&id=`$row.rule_id`"}"
                        class="action-item action-item-first" title="Delete Rule">Delete</a></span></td>
                </tr>
            {/foreach}
        </table>
        {/strip}

        {include file="CRM/common/pager.tpl" location="bottom"}

        </p>
    </fieldset>
    {* END Actions/Results section *}
{/if}
{literal}
  <script>
    function showRuleHelp(ruleId) {
      CRM.api3('CiviRuleRule', 'getsingle', {"id": ruleId})
        .done(function(result) {
        cj("#civirule_helptext_dialog-block").dialog({
          width: 600,
          height: 300,
          title: "Help for Rule " + result.label,
          buttons: {
            "Done": function() {
              cj(this).dialog("close");
            }
          }
        });
        cj("#civirule_helptext_dialog-block").html(result.help_text);
      });
    };
  </script>
{/literal}




