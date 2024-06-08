-- implement Functions and Stored Procedures.

-- CREATE PROCEDURE procedure_name (parameter1 data_type, parameter2 data_type, …) 
-- AS
-- BEGIN
-- — SQL statements to be executed 
-- END

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

-- Creating a Procedure
CREATE PROCEDURE GetCustomersByCountry @Country VARCHAR(50)
AS 
BEGIN
SELECT CustomerName, ContactName
FROM Customers
WHERE Country = @Country
END;
