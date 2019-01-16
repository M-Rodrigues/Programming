select class
from (
    select count(distinct student), class
    from courses
    group by class
    having count(distinct student) >= 5
) A