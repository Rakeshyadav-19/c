-- Example Table
CREATE TABLE Account(
    AccountID INT PRIMARY KEY,
    Balance DECIMAL(10, 2)
);

-- Insert Initial Data
INSERT INTO Account (AccountID, Balance) VALUES (1, 1000.00), (2, 1500.00);

-- Transaction Example
START TRANSACTION;

-- Update Balances
UPDATE Account SET Balance = Balance - 200.00 WHERE AccountID = 1;
UPDATE Account SET Balance = Balance + 200.00 WHERE AccountID = 2;

-- Commit Transaction
COMMIT;




-- Set Isolation Level
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- Begin Transaction
START TRANSACTION;

-- Check Balance
SET @Balance := (SELECT Balance FROM Account WHERE AccountID = 1);

-- Conditional Update
IF @Balance >= 500.00 THEN
    UPDATE Account SET Balance = Balance - 500.00 WHERE AccountID = 1;
    UPDATE Account SET Balance = Balance + 500.00 WHERE AccountID = 2;
ELSE
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Insufficient funds';
END IF;

-- Commit Transaction
COMMIT;
