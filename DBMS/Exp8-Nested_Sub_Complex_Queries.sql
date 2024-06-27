-- implementation of nested sub-queries, complex queries, views and Joins;

-- nested sub-queries
-- Sub queries with the Select Statement
SELECT *
FROM Student 
WHERE Roll_NO IN (SELECT Roll_NO FROM Student WHERE Roll_NO > 20);

-- Sub queries with the INSERT Statement
INSERT INTO Student(Roll_NO,First_Name) 
SELECT TeacherID,First_Name FROM Teachers 
WHERE  TeacherID IN (SELECT TeacherID FROM Teachers);

-- Sub queries with the UPDATE Statement
UPDATE Student
SET Roll_NO = 2000 + Roll_NO
WHERE Roll_NO >= (SELECT TeacherID FROM Teachers WHERE First_Name = "R" );

-- Sub queries with the DELETE Statement
DELETE FROM Student
WHERE Roll_NO IN (SELECT TeacherID FROM Teachers WHERE First_Name = "M" );


-- SQL JOIN:

CREATE TABLE Student1(
  ROLL_NO INT,
  NAME VARCHAR(255),
  ADDRESS VARCHAR(255),
  PHONE VARCHAR(255),
  Age INT
);
INSERT INTO Student1 (ROLL_NO, NAME, ADDRESS, PHONE, Age) 
  VALUES
    (1, 'HARSH', 'DELHI', 'XXXXXXXXXX', 18),
    (2, 'PRATIK', 'BIHAR', 'XXXXXXXXXX', 19),
    (3, 'RIYANKA', 'SILIGURI', 'XXXXXXXXXX', 20),
    (4, 'DEEP', 'RAMNAGAR', 'XXXXXXXXXX', 18),
    (5, 'SAPTARHI', 'KOLKATA', 'XXXXXXXXXX', 19),
    (6, 'DHANRAJ', 'BARABAJAR', 'XXXXXXXXXX', 20),
    (7, 'ROHIT', 'BALURGHAT', 'XXXXXXXXXX', 18),
    (8, 'NIRAJ', 'ALIPUR', 'XXXXXXXXXX', 19)
;

CREATE TABLE StudentCourse (
  COURSE_ID INT,
  ROLL_NO INT
);
INSERT INTO StudentCourse (COURSE_ID, ROLL_NO) VALUES
(1, 1),
(2, 2),
(2, 3),
(3, 4),
(1, 5),
(4, 9),
(5, 10),
(4, 11);

-- INNER JOIN
SELECT StudentCourse.COURSE_ID, Student1.NAME, Student1.AGE 
FROM Student1 
INNER JOIN StudentCourse
ON Student1.ROLL_NO = StudentCourse.ROLL_NO;

-- LEFT JOIN
SELECT Student1.NAME,StudentCourse.COURSE_ID 
FROM Student1
LEFT JOIN StudentCourse
ON StudentCourse.ROLL_NO = Student1.ROLL_NO;

--  RIGHT JOIN
SELECT Student1.NAME,StudentCourse.COURSE_ID 
FROM Student1
RIGHT JOIN StudentCourse
ON StudentCourse.ROLL_NO = Student1.ROLL_NO;

-- FULL JOIN
SELECT Student1.NAME, StudentCourse.COURSE_ID
FROM Student1
FULL JOIN StudentCourse
ON Student1.ROLL_NO = StudentCourse.ROLL_NO;
-- OR
SELECT Student1.NAME, StudentCourse.COURSE_ID
FROM Student1
LEFT JOIN StudentCourse
ON Student1.ROLL_NO = StudentCourse.ROLL_NO
UNION
SELECT Student1.NAME, StudentCourse.COURSE_ID
FROM Student1
RIGHT JOIN StudentCourse
ON Student1.ROLL_NO = StudentCourse.ROLL_NO;


-- NATURAL JOIN
SELECT StudentCourse.COURSE_ID, Student1.NAME, Student1.AGE 
FROM Student1 
NATURAL JOIN StudentCourse;



-- Views in SQL
-- Creating view
CREATE VIEW roll 
AS 
SELECT NAME, ADDRESS
FROM Student1
WHERE ROLL_NO > 5;

SELECT * FROM roll;

-- Deleting View
DROP VIEW roll;