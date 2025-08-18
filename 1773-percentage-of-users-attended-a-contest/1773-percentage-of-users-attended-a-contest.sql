select r.contest_id, round(count(r.contest_id)/(select count(user_id) from users)*100,2) as percentage
from register as r
group by r.contest_id 
order by percentage DESC, contest_id 
