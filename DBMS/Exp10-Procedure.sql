-- implement Functions and Stored Procedures.


-- To Execute the procedure
-- EXEC procedure_name parameter1_value, parameter2_value, ..

CREATE TABLE Customers( 
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(50), 
    ContactName VARCHAR(50),
    Country VARCHAR(50)
);

INSERT INTO Customers (CustomerID, CustomerName, ContactName, Country) 
VALUES
    (1, 'Shubham', 'Thakur', 'India'),
    (2, 'Aman ', 'Chopra', 'Australia'),
    (3, 'Naveen', 'Tulasi', 'Sri lanka'),
    (4, 'Aditya', 'Arpan', 'Austria'), 
    (5, 'Nishant. Salchichas S.A.', 'Jain', 'Spain')
;


USE DBMS;
-- Creating a Procedure
DELIMITER //
CREATE PROCEDURE Get_Data()
BEGIN
    SELECT * From Customers WHERE CustomerID = 1;
END //
DELIMITER ;


CALL Get_Data();