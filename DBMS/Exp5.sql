-- implementation of Data Manipulation Language (DML) Queries.

USE dbms;

-- INSERT:
INSERT INTO students (Roll_No, fName, Email) 
    VALUES 
        (24, "Patil", "dude5057@gmail.com"),
        (32, "Badkar", "prabhu@gamil.com"),
        (21, "Patil", "Patil@gmail.com"),
        (29, "Yadav", "rax@gmail.com")
;

-- UPDATE:
UPDATE students SET Roll_NO = 27 WHERE fName = "Yadav";

-- DELETE:  (Omit the WHERE clause, delete every row)
DELETE FROM students WHERE fName = "Yadav";

-- SELECT:
Select * from students;