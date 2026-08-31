# Write your MySQL query statement below
SELECT customer_id , COUNT(*) AS count_no_trans
FROM Visits V LEFT OUTER JOIN Transactions T ON 
V.visit_id = T.visit_id
where T.amount IS NULL
Group by customer_id , T.visit_id
