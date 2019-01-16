delete from Person
where Id not in (
    select mm
    from (
        select min(Id) mm
        from Person
        group by Email 
    ) A
)