# Write your MySQL query statement below
select pr.product_name as product_name ,s.year as year ,s.price as price
from sales s
inner join product pr
on s.product_id=pr.product_id