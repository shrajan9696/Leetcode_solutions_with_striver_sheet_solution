# Write your MySQL query statement below

SELECT E1.name as Employee from Employee as E1 JOIN Employee as E2 on E1.managerId=E2.id  and E1.salary>E2.salary;