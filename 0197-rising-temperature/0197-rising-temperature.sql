# Write your MySQL query statement below
SELECT w1.Id FROM Weather W1 INNER JOIN Weather W2 
on W1.RECORDDATE = DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature
