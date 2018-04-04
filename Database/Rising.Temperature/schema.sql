-- Create table and insert data
Create table If Not Exists Weather (Id int, Date date, Temperature int);
Truncate table Weather;
insert into Weather (Id, Date, Temperature) values ('1', '2015-01-01', '10');
insert into Weather (Id, Date, Temperature) values ('2', '2015-01-02', '25');
insert into Weather (Id, Date, Temperature) values ('3', '2015-01-03', '20');
insert into Weather (Id, Date, Temperature) values ('4', '2015-01-04', '30');

-- Solution 1 subquery
SELECT Id
FROM Weather a
WHERE
    Temperature >
        (
        SELECT Temperature
        FROM Weather b
        WHERE DATEDIFF(a.Date, b.Date) = 1 AND a.Temperature > b.Temperature
        )
;

-- Solution 2 JOIN
SELECT Weather.Id AS 'Id'
FROM Weather
    JOIN Weather a
    ON DATEDIFF(Weather.Date, a.Date) = 1 AND Weather.Temperature > a.Temperature
;
