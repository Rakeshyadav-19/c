-- implementation of SQL constructs for aggregating data, use of group by, Having clauses.

USE dbms;
-- FUN( [ALL|DISTINCT] expression)

-- COUNT() Function - The COUNT() function returns the number of rows in a database table.
SELECT COUNT(*) From students;
SELECT COUNT(*) From teachers;

-- SUM() Function - The SUM() function returns the total sum of a numeric column.
SELECT SUM(ID) FROM teachers;

-- AVG() Function - The AVG() function calculates the average of a set of values.
SELECT AVG(ID) FROM teachers;

-- MIN() Function - The MIN() aggregate function returns the lowest value (minimum) in a set of non-NULL values.
SELECT MIN(ID) FROM teachers;

-- MAX() Function - The MAX() aggregate function returns the highest value (maximum) in a set of non-NULL values.
SELECT MAX(ID) FROM teachers;

-- The SQL GROUP BY Statement - groups rows that have the same values into summary rows.
SELECT COUNT(Roll_NO),fName 
FROM students 
GROUP BY fName;

-- SQL HAVING Clause - Added because the WHERE keyword cannot be used with aggregate functions.
SELECT COUNT(Roll_NO),fName 
FROM students 
GROUP BY fName
HAVING COUNT(Roll_NO) > 1;