-- Implementation of Data Definition Language (DDL) Queries.

-- CREATE Command
Create Database Books;

-- create a new table:
CREATE TABLE Student(
    Roll_No. Int ,
    First_Name Varchar (20) , 
    Last_Name Varchar (20) , 
    Age Int ,
    Marks Int ,
);

-- remove a database:
DROP DATABASE Books;

-- remove a table:
DROP TABLE Student;

-- #ALTER Command:

-- 1.add a newfield in the table:
ALTER TABLE Student ADD Fathers_Name Varchar(60);

-- 2.remove a column from the table:
ALTER TABLE Student DROP Age, Marks;

-- modify the column of the table:
ALTER TABLE Students 
MODIFY column Last_Name varchar(25); 
