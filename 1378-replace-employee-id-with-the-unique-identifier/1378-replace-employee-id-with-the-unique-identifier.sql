# Write your MySQL query statement below
SELECT  EU.unique_id , E.name FROM EMPLOYEES E LEFT OUTER JOIN EMPLOYEEUNI EU 
ON E.ID = EU.ID;