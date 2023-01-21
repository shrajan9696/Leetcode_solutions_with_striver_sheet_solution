# Write your MySQL query statement below

SELECT email as Email FROM Person Group By(email) HAVING COUNT(*)>1;