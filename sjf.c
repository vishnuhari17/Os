#include<stdio.h>
#include<string.h>
struct process
{
        int AT,BT,WT,TT,status;
        char pname[10];
}p[10];
struct gantt
{
        int ST,CT;
        char pname[10];
}g[10];
void main()
{
        int n,i=0,j=0,k=0,m,idle=0,flag,ls=0,num=0;
        float wait=0,turn=0;
        printf("Enter the number of process:");
        scanf("%d",&n);
        for(m=0;m<n;m++)
        {
                printf("enter details of process %d",m+1);
                printf("\n");
                printf("Name:");
                scanf(" %s",p[m].pname);
                printf("Arrival Time:");
                scanf("%d",&p[m].AT);
                printf("Burst Time:");
                scanf("%d",&p[m].BT);
                printf("\n");
                p[m].status=0;
        }
        while(ls<n)
        {
                flag=0;
                for(j=0;j<n;j++)
                {
                        if((p[j].status==0)&&(p[j].AT<=i)&&(flag==0))
                        {
                                k=j;
                                flag++;
                        }
                        if((p[j].status==0)&&(p[j].AT<=i)&&(flag>0))
                        {
                                if(p[j].BT<p[k].BT)
                                {
                                        k=j;
                                }
                        }
                }
                if((flag==0)&&(idle==0))
                {
                        strcpy(g[num].pname,"idle");
                        g[num].ST=i;
                        idle=1;
                        i++;
                }
                else if(flag>0)
                {
                        if(idle==1)
                        {
                                g[num].CT=i;
                                num++;
                        }
                        strcpy(g[num].pname,p[k].pname);
                        g[num].ST=i;
                        g[num].CT=i+p[k].BT;
                        p[k].WT=g[num].ST-p[k].AT;
                        p[k].TT=g[num].CT-p[k].AT;
                        i=g[num].CT;
                        num++;
                        p[k].status=1;
                        idle=0;
                        ls++;
                        k++;
                }
                else
                {
                        i++;
                }
        }
        printf("Name\tAT\tBT\tTT\tWT\n");
        for(m=0;m<n;m++)
        {
                printf("%s\t%d\t%d\t%d\t%d\n",p[m].pname,p[m].AT,p[m].BT,p[m].TT,p[m].WT);
                wait=wait+p[m].WT;
                turn=turn+p[m].TT;
        }
        printf("\nGantt chart\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("|");
        for(m=0;m<num;m++)
        {
                printf("%s\t|",g[m].pname);
        }
        printf("\n-------------------------------------------------------------------------------\n");
        printf("%d\t",g[0].ST);
        for(m=0;m<num;m++)
        {
                printf("%d\t",g[m].CT);
        }
        printf("\nAverage waiting time = %f",wait/n);
        printf("\nAverage turnaround time = %f\n",turn/n);
}


Enter the number of process:3
enter details of process 1
Name:p0
Arrival Time:2
Burst Time:3
Priority:2

enter details of process 2
Name:p1
Arrival Time:1
Burst Time:3
Priority:2

enter details of process 3
Name:p2
Arrival Time:3
Burst Time:2
Priority:4

Name        AT        BT        TT        WT
p0            2        3        5        2
p1            1        3        3        0
p2            3        2        6        4

Gantt chart
-------------------------------------------------------------------------------
|idle        |p1        |p0        |p2        |
-------------------------------------------------------------------------------
0            1        4        7        9        
Average waiting time = 2.000000
Average turnaround time = 4.666667