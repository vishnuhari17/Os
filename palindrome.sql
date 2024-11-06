DECLARE
    str varchar(10):='&str';
    revstr varchar(10);
    leng number;
BEGIN
    revstr:='';
    leng:=length(str);
    FOR i IN REVERSE 1..leng LOOP
        revstr:=revstr||substr(str,i,1);
    END LOOP;
    IF str=revstr THEN
        dbms_output.put_line('Palindrome');
    ELSE
        dbms_output.put_line('Not Palindrome');
    END IF;
END;
/