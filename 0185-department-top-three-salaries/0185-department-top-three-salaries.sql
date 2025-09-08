# Write your MySQL query statement below
select  Department, Employee, Salary from (
    select d.name as Department, e.name as Employee, e.Salary as Salary, Dense_rank() over (partition by d.name order by e.Salary desc) as rnk
    from employee as e
    join Department as d
    on e.departmentId = d.id 
) as a
    where rnk<=3
