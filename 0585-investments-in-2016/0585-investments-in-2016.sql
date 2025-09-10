# Write your MySQL query statement below
select Round(sum(tiv_2016),2) as tiv_2016
from Insurance 
where tiv_2015 in (
    Select tiv_2015 
    from Insurance 
    group by tiv_2015 
    having count(*)>1
)
AND (lat, lon) in (
    select lat,lon 
    FROM insurance 
    group by lat,lon
    having count(*) =1
)

