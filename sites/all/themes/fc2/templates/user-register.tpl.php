
<div class="large-12 left">
<div class="event-user-login-link">
	<h3>Welcome to Friendship Circle. Please take a moment to create an account in order to access the different sections in this site. If you experience any difficulty, please contact the office.</h3>
If you already have an account, <a href="/user/login">Login Here</a>
</div>
<fieldset>
    <legend><i class="fa fa-lock" aria-hidden="true"></i> Account information</legend>
<div class="large-6 columns"> <?php print render($form['account']['mail']); ?> </div>
<div class="large-6 columns"> <?php print render($form['account']['conf_mail']); ?> </div>
<div class="large-6 columns"> <?php print render($form['account']['name']); ?> </div>
<div class="large-6 columns"><?php print render($form['account']['pass']);?></div>
</fieldset>


<?php
print drupal_render_children($form);
print drupal_render($form['actions']);
?>


</div>