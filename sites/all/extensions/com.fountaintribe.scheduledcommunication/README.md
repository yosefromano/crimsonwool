# com.fountaintribe.scheduledcommunication

Provides 2 daily scheduled jobs. They each need 2 parameters: a group name and a message template name. 

The 'email2each' scheduled job will send 1 email to each contact in the group. The contents of the email will be the message template.

The 'PDFBundle.sendpdf' scheduled job will generate 1 large PDF file for the entire group. That 1 PDF file will be emailed to one contact, presumably a staff person who will print the PDF and mail things using snail mail. This is helpful for communicating with people who do not have an email address, or simply prefer hard-copy mail.
