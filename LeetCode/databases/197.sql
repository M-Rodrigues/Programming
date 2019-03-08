select Id
from Weather A
where A.Temperature > (
    select B.Temperature
    from Weather B
    where B.RecordDate = date(A.RecordDate - interval 1 day)
)