{*
 +--------------------------------------------------------------------+
 | CiviCRM version 4.4                                                |
 +--------------------------------------------------------------------+
 | Copyright CiviCRM LLC (c) 2004-2013                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
*}
{* Search criteria form elements - Find Experts *}

{* Set title for search criteria accordion *}
{capture assign=editTitle}{ts}Edit Search Criteria for CiviRules Rules(s){/ts}{/capture}

{strip}
<div class="crm-block crm-form-block crm-basic-criteria-form-block">
    <div class="crm-accordion-wrapper crm-case_search-accordion {if $rows}collapsed{/if}">
        <div class="crm-accordion-header crm-master-accordion-header">{$editTitle}</div><!-- /.crm-accordion-header -->
        <div class="crm-accordion-body">
            <table class="form-layout">
                <tbody>
                    {if $form.rule_label}
                        <tr>
                            <td><label for="rule_label">{ts}Rule Label contains(s){/ts}</label></td>
                            <td>{$form.rule_label.html}</td>
                        </tr>
                    {/if}
                    {if $form.rule_tag_id}
                        <tr>
                            <td><label for="rule_tag_id-select">{ts}Rule Tag(s){/ts}</label></td>
                            <td class="select2-container select2-container-multi crm-select2 crm-form-multiselect">{$form.rule_tag_id.html}</td>
                        </tr>
                    {/if}
                    {if $form.rule_trigger_id}
                        <tr>
                            <td><label for="rule_trigger_id-select">{ts}Rule Trigger(s){/ts}</label></td>
                            <td class="select2-container select2-container-multi crm-select2 crm-form-multiselect">{$form.rule_trigger_id.html}
                        </tr>
                    {/if}
                    {if $form.only_active_rules}
                        <tr>
                            <td><label for="only_active_rules">{$form.only_active_rules.label}</label></td>
                            <td>{$form.only_active_rules.html}</td>
                        </tr>
                    {/if}
                </tbody>
            </table>
            <div class="crm-submit-buttons">
              {include file="CRM/common/formButtons.tpl"}
            </div>
        </div><!- /.crm-accordion-body -->
    </div><!-- /.crm-accordion-wrapper -->
</div><!-- /.crm-form-block -->
{/strip}


