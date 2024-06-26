-- implementation of SQL constructs for aggregating data, use of group by, Having clauses.

USE DBMS;
-- Various types of SQL aggregate functions are:
    -- • Count()
    -- • Sum()
    -- • Avg()
    -- • Min()
    -- • Max()
;

-- COUNT() Function - The COUNT() function returns the number of rows in a database table.
SELECT COUNT(*) From Student;
SELECT COUNT(*) From Teachers;

-- SUM() Function - The SUM() function returns the total sum of a numeric column.
SELECT SUM(Age) FROM Student;

-- AVG() Function - The AVG() function calculates the average of a set of values.
SELECT AVG(Age) FROM Student;

-- MIN() Function - The MIN() aggregate function returns the lowest value (minimum) in a set of non-NULL values.
SELECT MIN(TeacherID) FROM Teachers;

-- MAX() Function - The MAX() aggregate function returns the highest value (maximum) in a set of non-NULL values.
SELECT MAX(TeacherID) FROM Teachers;

-- The SQL GROUP BY Statement - groups rows that have the same values into summary rows.
SELECT COUNT(Last_Name),Last_Name
FROM Student 
GROUP BY Last_Name;
SELECT COUNT(First_Name),First_Name
FROM Teachers 
GROUP BY First_Name;

-- SQL HAVING Clause - Added because the WHERE keyword cannot be used with aggregate functions.
SELECT COUNT(Roll_NO),First_Name 
FROM Student
GROUP BY First_Name
HAVING COUNT(Roll_NO) > 1;