# Write your MySQL query statement below
select e1.name 
from employee as e1 
join employee as e2
on e1.id = e2.managerID
group by e2.managerID
having count(e2.managerID)>=5