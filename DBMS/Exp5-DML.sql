-- implementation of Data Manipulation Language (DML) Queries.
CREATE DATABASE DBMS;

USE DBMS;

CREATE TABLE Student (Roll_No, First_Name, Last_Name, Age, Marks);

-- INSERT:
INSERT INTO Student (Roll_No, First_Name, Last_Name, Age, Marks) 
    VALUES 
        (7, "Thala", "NO", 70, 100),
        (14, "Rony", "kale",45, 60 ),
        (21, "Thala", "for reason", 77, 777),
        (28, "Tony", "Lale", 07, 007)
;

-- UPDATE:
UPDATE Student SET Last_Name = "King" WHERE First_Name = "Thala";

-- DELETE:  (Omit the WHERE clause, delete every row)
DELETE FROM Student WHERE First_Name = "Rony";

-- SELECT:
Select * from Student;

