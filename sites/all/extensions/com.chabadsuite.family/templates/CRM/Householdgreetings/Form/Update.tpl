<div class="crm-block crm-form-block">
  {if $smarty.get.state eq 'done'}
    <div class="help">
      {ts}Update completed Successfully.{/ts}<br/>
    </div>
  {else}
    <p>{ts}Running this will update greetings for all contact(s) of type 'Individual'{/ts}</p>
    <div class="crm-submit-buttons">
      {include file="CRM/common/formButtons.tpl"}
    </div>
  {/if}
</div>
