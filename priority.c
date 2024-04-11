#include<stdio.h>
#include<string.h>
struct process
{
        int AT,BT,WT,TT,PR,status;
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
                printf("Priority:");
                scanf("%d",&p[m].PR);
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
                                if(p[j].PR<p[k].PR)
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
        printf("Name\tAT\tBT\tPR\tTT\tWT\n");
        for(m=0;m<n;m++)
        {
                printf("%s\t%d\t%d\t%d\t%d\t%d\n",p[m].pname,p[m].AT,p[m].BT,p[m].PR,p[m].TT,p[m].WT);
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



Enter the number of process:4
enter details of process 1
Name:a
Arrival Time:0
Burst Time:2
Priority:2

enter details of process 2
Name:b
Arrival Time:0
Burst Time:1
Priority:1

enter details of process 3
Name:c
Arrival Time:1
Burst Time:3
Priority:1

enter details of process 4
Name:d
Arrival Time:8
Burst Time:2
Priority:1

Name        AT        BT        PR        TT        WT
p0            0        2        2        6        4
p1      0        1        1        1        0
p2            1        3        1        3        0
p3            8        2        1        2        0

Gantt chart
-------------------------------------------------------------------------------
|p1        |p2        |p0        |idle        |p3        |
-------------------------------------------------------------------------------
0        1        4        6           8        10        
Average waiting time = 1.000000
Average turnaround time = 3.000000