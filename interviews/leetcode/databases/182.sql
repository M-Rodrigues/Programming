select Email 
from (
    select count(*), B.Email
    from Person B
    group by B.Email
    having count(*) > 1
) A