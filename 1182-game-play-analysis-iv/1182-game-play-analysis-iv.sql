select Round(Count(distinct player_id)/(select count(distinct player_id) from activity),2) as fraction
from activity 
where (player_id , DATE_SUB(event_date, INTERVAL 1 Day)) in(
    select player_id, MIN(event_date) as first_login
    from activity 
    group by player_id
)