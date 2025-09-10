Select 
    Case 
        when 
        id = (select max(id) from seat) and mod(id,2)=1
        then id 
        when 
            mod(id,2)=1
            then 
                id+1

            Else 
                id-1
        end as id , Student 

from seat 
order by id 