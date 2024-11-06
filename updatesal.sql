CREATE OR REPLACE FUNCTION update_sal(eid in varchar,incsal in number)
RETURN number 
IS
        net_sal number(6);
        incc number(6);
        sal emp.SALARY%type;
BEGIN 
        SELECT SALARY INTO sal FROM emp WHERE ENO = eid;
        dbms_output.put_line('Old Salary: '||sal);
        incc:=incsal;
        net_sal:=sal+incc;
        UPDATE emp SET NET_SALARY = net_sal,UPDATE_DATE=sysdate WHERE ENO=eid;
        return net_sal;
EXCEPTION
        when no_data_found then
                return NULL;
END;
/

DECLARE
        empid varchar(5):='&ENO';
        incsal number(6):=&Salary_increment;
        netsal number(6);
BEGIN
        netsal:=update_sal(empid,incsal);
        if netsal is NOT NULL then
                dbms_output.put_line('Current Salary:' ||netsal);
        else
                dbms_output.put_line('Employee ID NOT FOUND!!!');
        end if;
END;
/


