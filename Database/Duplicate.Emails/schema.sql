-- Create table and insert data
Create table If Not Exists Person (Id int, Email varchar(255));
Truncate table Person;
insert into Person (Id, Email) values ('1', 'a@b.com');
insert into Person (Id, Email) values ('2', 'c@d.com');
insert into Person (Id, Email) values ('3', 'a@b.com');

-- Solution 1
SELECT Email
FROM
    (
    SELECT Email, COUNT(Email) AS count
    FROM Person
    GROUP BY (Email)
    ) AS tmp
WHERE count > 1;

-- Solution 2
SELECT Email FROM Person GROUP BY (Email) HAVING COUNT(*) > 1;
