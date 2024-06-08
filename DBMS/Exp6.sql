-- implementation of SQL SELECT statement for displaying / extracting data from single table or multiple tables.

USE dbms 

-- From a single table:
select * FROM students;

-- From multiple tables:

-- 1.Using Joins:
SELECT students.Roll_No,students.fName,teachers.fName,teachers.ID 
FROM students
INNER JOIN teachers
ON students.fName =  teachers.fName;

-- 2.Using Sub query:
select Roll_No,fName,Email 
from students
where fName=(select fName from teachers WHERE fName="Patil");