-- Implementation of Data Definition Language (DDL) Queries.

-- CREATE Command
Create Database Books;

USE DBMS;
-- create a new table:
CREATE TABLE Student(
    Roll_No Int (10),
    First_Name Varchar (20) , 
    Last_Name Varchar (20) , 
    Age Int (2),
    Marks Int (3)
);


-- #ALTER Command:

-- 1.add a newfield in the table:
ALTER TABLE Student 
ADD column Fathers_Name Varchar(60);

-- 2.remove a column from the table:
ALTER TABLE Student DROP Fathers_Name;

-- modify the column of the table:
ALTER TABLE Student 
MODIFY column Last_Name varchar(25); --Changes the size of Last_Nmae to 25 from 20

-- remove a table:
DROP TABLE Student;

-- remove a database:
DROP DATABASE Books;