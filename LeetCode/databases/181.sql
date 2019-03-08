select A.Name Employee
from Employee A
inner join Employee B on A.ManagerId = B.Id
where A.Salary > B.Salary