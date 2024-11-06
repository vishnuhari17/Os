CREATE TABLE MARKS(
    ROLL_NO NUMBER(9) PRIMARY KEY,
    MARK1 NUMBER(3),
    MARK2 NUMBER(3),
    MARK3 NUMBER(3),
    MARK4 NUMBER(3),
    MARK5 NUMBER(3)
);


INSERT INTO MARKS VALUES(1, 90, 80, 70, 60, 50);
INSERT INTO MARKS VALUES(2, 80, 70, 60, 50, 40);
INSERT INTO MARKS VALUES(3, 70, 60, 50, 40, 30);
INSERT INTO MARKS VALUES(4, 60, 50, 40, 30, 20);
INSERT INTO MARKS VALUES(5, 50, 40, 30, 20, 10);
INSERT INTO MARKS VALUES(6, 40, 30, 20, 10, 0);
INSERT INTO MARKS VALUES(7, 30, 20, 10, 0, 0);
INSERT INTO MARKS VALUES(8, 20, 10, 0, 0, 0);




create table emp (
    ENO varchar(5) primary key,
    ENAME varchar(20),
    JOB varchar(10),
    SALARY number(6),
    NET_SALARY number(6),
    UPDATE_DATE date
);

INSERT into emp(eno,ename,job,Salary) values ('E001','John','Manager',50000);
INSERT into emp(eno,ename,job,Salary) values ('E002','Doe','Clerk',20000);
INSERT into emp(eno,ename,job,Salary) values ('E003','Jane','Clerk',15000);
INSERT into emp(eno,ename,job,Salary) values ('E004','Smith','Clerk',10000);
INSERT into emp(eno,ename,job,Salary) values ('E005','Doe','Clerk',20000);
INSERT into emp(eno,ename,job,Salary) values ('E006','Jane','Clerk',15000);
INSERT into emp(eno,ename,job,Salary) values ('E007','Smith','Clerk',10000);




CREATE TABLE bill_details(CONSUMER_NO VARCHAR(10) PRIMARY KEY,PRESENT_READING NUMBER(6),PREVIOUS_READING NUMBER(6),UNITS_CONSUMED NUMBER(6),PAYABLE_AMOUNT NUMBER(8));

insert into bill_details(consumer_no,present_reading,previous_reading) values ('C1',100,35);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C2',550,200);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C3',250,120);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C4',998,334);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C5',876,123);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C6',1000,500);
insert into bill_details(consumer_no,present_reading,previous_reading) values ('C7',500,100);

