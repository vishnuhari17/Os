CREATE OR REPLACE PROCEDURE grde(r IN number,g OUT VARCHAR)
IS 
        m1 marks.mark1%type;
        m2 marks.mark2%type;
        m3 marks.mark3%type;
        m4 marks.mark4%type;
        m5 marks.mark5%type;        
        total number(3);
        avge number(3);
BEGIN
        SELECT MARK1,MARK2,MARK3,MARK4,MARK5 INTO m1,m2,m3,m4,m5 FROM marks WHERE ROLL_NO=r;
        total:=m1+m2+m3+m4+m5;
        avge:=floor(total/5);
        if avge>=90 then
                g:='S';
        elsif avge>=85 and avge<90 then
                g:='A+';
        elsif avge>=80 and avge<85 then
                g:='A';
        elsif avge>=75 and avge<80 then
                g:='B+';
        elsif avge>=70 and avge<75 then
                g:='B';
        elsif avge>=65 and avge<70 then
                g:='C+';
        elsif avge>=60 and avge<65 then
                g:='C';
        elsif avge>=55 and avge<60 then
                g:='D';
        elsif avge>=50 and avge<55 then
                g:='P';
        else
                g:='F';
        end if;
EXCEPTION
        when no_data_found then
                g:='';
END;
/

DECLARE
        r number(9):=&ROLL_NO;
        grade varchar(2);
BEGIN 
        grde(r,grade);
        if grade is NOT NULL then
                dbms_output.put_line('Grade:'||grade);
        else
        dbms_output.put_line('Roll No. NOT FOUND!!!');
        end if;
END;
/

