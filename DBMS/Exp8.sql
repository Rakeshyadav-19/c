-- implementation of nested sub-queries, complex queries, views and Joins;

-- nested sub-queries
-- Sub queries with the Select Statement
SELECT *
FROM students 
WHERE Roll_NO IN (SELECT Roll_NO FROM students WHERE Roll_NO > 24);

-- Sub queries with the INSERT Statement
INSERT INTO students(Roll_NO,fName,Email) 
SELECT * FROM teachers 
WHERE  ID IN (SELECT ID FROM teachers);

-- Sub queries with the UPDATE Statement
UPDATE students
SET Roll_NO = 2000 + Roll_NO
WHERE Roll_NO >= 21
WHERE fName IN (SELECT fName FROM teachers WHERE fName = "Patil" );

-- Sub queries with the DELETE Statement
DELETE FROM students
WHERE fName IN (SELECT fName FROM teachers WHERE fName = "Patil" );


-- SQL JOIN:
CREATE TABLE Students1 (
  ROLL_NO INT,
  NAME VARCHAR(255),
  ADDRESS VARCHAR(255),
  PHONE VARCHAR(255),
  Age INT
);
INSERT INTO Students1 (ROLL_NO, NAME, ADDRESS, PHONE, Age) VALUES
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
SELECT StudentCourse.COURSE_ID, Students1.NAME, Students1.AGE 
FROM Students1 
INNER JOIN StudentCourse
ON Students1.ROLL_NO = StudentCourse.ROLL_NO;

-- LEFT JOIN
SELECT Students1.NAME,StudentCourse.COURSE_ID 
FROM Students1
LEFT JOIN StudentCourse
ON StudentCourse.ROLL_NO = Students1.ROLL_NO;

--  RIGHT JOIN
SELECT Students1.NAME,StudentCourse.COURSE_ID 
FROM Students1
RIGHT JOIN StudentCourse
ON StudentCourse.ROLL_NO = Students1.ROLL_NO;

-- FULL JOIN  ------------------NOT WORKING
SELECT Students1.NAME,StudentCourse.COURSE_ID 
FROM Students1
FULL JOIN StudentCourse
ON StudentCourse.ROLL_NO = Students1.ROLL_NO;

-- NATURAL JOIN  ------------------NOT WORKING
SELECT StudentCourse.COURSE_ID, Students1.NAME, Students1.AGE 
FROM Students1 
NATURAL JOIN StudentCourse
ON Students1.ROLL_NO = StudentCourse.ROLL_NO;


-- Views in SQL
-- Creating view
CREATE VIEW roll AS SELECT NAME, ADDRESS
FROM Students1
WHERE ROLL_NO > 5;
SELECT * FROM roll ;

-- Deleting View
DROP VIEW roll;