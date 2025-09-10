# Write your MySQL query statement below
select Department,  Employee, Salary from 
(
    select d.name as Department, e.name as employee, e.salary as Salary, 
    dense_rank() over (partition by d.name order by Salary Desc) as rnk 
    from Employee as e 
    join Department as d
    on e.DepartmentId = d.id  
) as a
where rnk<=3