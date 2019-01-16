select max(Salary) SecondHighestSalary
from (
    select Salary 
    from Employee
    where Salary < (
        select max(salary) Salary
        from Employee
    )
) A