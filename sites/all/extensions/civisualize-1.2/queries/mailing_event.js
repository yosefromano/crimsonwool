{"query":"
select DATE_FORMAT(time_stamp,'%Y-%m-%d %H:%i') as date, count(*) as count 
from(
select contact_id, min(time_stamp) as time_stamp
  from civicrm_mailing_event_opened 
  join civicrm_mailing_event_queue q on event_queue_id=q.id 
  join civicrm_mailing_job j on q.job_id=j.id and j.is_test=false 
  and mailing_id=%1 group by contact_id
) o group by date
","params":{"1":{"name":"mailing_id","type":"Integer"}}}
