-- implement Triggers.
use DBMS;

CREATE TABLE Student2(
    tid INT(4) PRIMARY KEY,
    name varchar(30),
    sub1 int(2),
    sub2 int(2),
    sub3 int(2),
    total int(3),
    per int(3)
);

-- Create trigger [trigger_name] 
-- [before | after]
-- {insert | update | delete} 
-- on [table_name]
-- [for each row] 
-- [trigger_body]

CREATE TRIGGER stud_marks 
BEFORE INSERT
ON Student2
FOR EACH ROW
SET NEW.total = NEW.sub1 + NEW.sub2 + NEW.sub3, NEW.per = (NEW.sub1 + NEW.sub2 + NEW.sub3) * 60 / 100;


INSERT INTO Student2 values(0, "ABCDE", 20, 20, 20, 0, 0);