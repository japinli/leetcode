-- Create table and insert data
Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
Truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', 'None');
insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', 'None');


-- Solution 1
SELECT Salary AS Employee
FROM Employee AS a LEFT JOIN Employee AS b ON a.ManagerId = b.Id
WHERE a.Salary > m.Salary;

-- Solution 2
SELECT e.Name AS Employee
FROM Employee AS e JOIN Employee AS m
on e.ManagerId = m.Id AND e.Salary > m.Salary;
