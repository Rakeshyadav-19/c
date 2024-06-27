-- implementation of SQL SELECT statement for displaying / extracting data from single table or multiple tables.

USE DBMS;

-- From a single table:
select * FROM Student;


CREATE TABLE Teachers (
    TeacherID INT,
    First_Name VARCHAR(30),
    Email VARCHAR(25)
);

INSERT INTO Teachers (TeacherID, First_Name, Email) 
    VALUES 
        (7, "M", "MSD@gmail.com"),
        (14, "R", "RS@gmail.com"),
        (21, "V", "VK@gmail.com")
;


-- From multiple tables:

-- 1.Using Joins:
SELECT Student.Roll_No, Student.Last_Name, Teachers.First_Name, Teachers.TeacherID 
FROM Student
INNER JOIN Teachers
ON Student.Roll_No =  Teachers.TeacherID;

-- 2.UsinExp5g Sub query:
select Roll_No,First_Name
from Student
where Roll_No=(select TeacherID from Teachers WHERE TeacherID=7);