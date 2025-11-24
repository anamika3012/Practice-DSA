# Write your MySQL query statement below
SELECT E1.name "Employee" FROM Employee E1 WHERE salary > (SELECT salary FROM Employee E2 
WHERE E1.managerId = e2.id);