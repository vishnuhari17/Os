declare
        pres bill_details.PRESENT_READING%type;
        prev bill_details.PREVIOUS_READING%type;
        units bill_details.UNITS_CONSUMED%type;
        amt bill_details.PAYABLE_AMOUNT%type;
        cno bill_details.CONSUMER_NO%type;
        cursor cur is SELECT CONSUMER_NO,PRESENT_READING,PREVIOUS_READING FROM bill_details;
begin
        open cur;
        if cur%ISOPEN then
        loop
                fetch cur into cno,pres,prev;
                exit when cur%NOTFOUND;
                units:=pres-prev;
                if units<=50 then
                        amt:=units*5;
                elsif units>50 and units<=100 then 
                        amt:=50*5+(units-50)*10;
                elsif units>100 and units<=200 then 
                        amt:=50*5+50*10+(units-100)*15;
                elsif units>200 then 
                        amt:=50*5+50*10+100*15+(units-200)*20;
                else 
                        amt:=0;
                end if;
                UPDATE bill_details SET UNITS_CONSUMED=units,PAYABLE_AMOUNT=amt WHERE CONSUMER_NO=cno;
                commit;
        end loop;
        close cur;
        else
                dbms_output.put_line('Cursor NOT OPENED');
        end if;
end;
/
