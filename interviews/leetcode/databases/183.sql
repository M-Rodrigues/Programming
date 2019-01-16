select A.Name Customers
from Customers A
left join Orders B on B.CustomerId = A.Id
where B.CustomerId is null