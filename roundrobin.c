#include<stdio.h>
#include<string.h>
int q[100],front=-1,rear=0;
struct process
{
        char pname[20];
        int at,bt,wt,tt,status,left;
}p[20];
struct gantt
{
        char pname[20];
        int st,ct;
}g[20];
void enqueue(int j)
{
        q[rear]=j;
        rear++;
        if(front==-1)
                front++;
}
int dequeue()
{
        int item;
        item=q[front];
        front++;
        if(front==rear)
        {
                front=-1;
                rear=0;
        }
        return item;
}
void main()
{
        int n,i,j,idle=0,k,num,ls,t,m=0;
        float wait=0,turn=0;
        num=0;
        printf("\nEnter the number of processes:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nenter the details of process %d",i+1);
                printf("\nEnter the process name:");
                scanf(" %s",p[i].pname);
                printf("Enter the arrival time:");
                scanf("%d",&p[i].at);
                printf("Enter the burst time:");
                scanf("%d",&p[i].bt);
                p[i].left=p[i].bt;
                p[i].status=0;
        }
        printf("\nEnter the time quantum:");
        scanf("%d",&t);
        ls=0;
        idle=0;
        i=0;
        while(ls<n)
        {
                for(j=0;j<n;j++)
                {
                        if(p[j].status==0 && p[j].at<=i)
                        {
                                enqueue(j);
                                p[j].status=1;
                        }
                }
                if(idle==0 && front == -1)
                {
                        strcpy(g[num].pname,"idle");
                        g[num].st=i;
                        idle=1;
                        i++;
                }
                else if(front!=-1)
                {
                        if(idle==1)
                        {
                                g[num].ct=i;
                                idle=0;
                                num++;
                        }        
                        k=dequeue();
                        g[num].st=i;
                        strcpy(g[num].pname,p[k].pname);
                        if(p[k].left<=t)
                        {
                                g[num].ct=i+p[k].left;
                                i=g[num].ct;
                                p[k].tt=i-p[k].at;
                                p[k].wt=p[k].tt-p[k].bt;
                                p[k].status=2;
                                ls++;
                                num++;
                        }
                        else
                        {
                                g[num].ct=i+t;
                                i=i+t;
                                p[k].left=p[k].left-t;
                                num++;
                                for(j=0;j<n;j++)
                                {
                                        if(p[j].status==0 && p[j].at<=i)
                                        {
                                                enqueue(j);
                                                p[j].status=1;
                                        }
                                }
                                enqueue(k);
                        }
                }
                else
                {
                        i++;
                }
        }
        printf("Name\tAT\tBT\tTT\tWT\n");
        for(m=0;m<n;m++)
        {
                printf("%s\t%d\t%d\t%d\t%d\n",p[m].pname,p[m].at,p[m].bt,p[m].tt,p[m].wt);
                wait=wait+p[m].wt;
                turn=turn+p[m].tt;
        }
        printf("\nGantt chart\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("|");
        for(m=0;m<num;m++)
        {
                if(strcmp(g[m].pname,g[m+1].pname)==0)
                {
                        continue;
                }
                else
                {
                        printf("%s\t|",g[m].pname);
                }
        }
        printf("\n-----------------------------------------------------------------------------------\n");
        printf("%d\t",g[0].st);
        for(m=0;m<num;m++)
        {
                if(strcmp(g[m].pname,g[m+1].pname)==0)
                {
                        continue;
                }
                else
                {
                        printf("%d\t",g[m].ct);
                }
        }
        printf("\nAverage waiting time = %f",wait/n);
        printf("\nAverage turnaround time = %f\n",turn/n);
}





Enter the number of processes:4

enter the details of process 1
Enter the process name:p0
Enter the arrival time:0
Enter the burst time:4

enter the details of process 2
Enter the process name:p1
Enter the arrival time:2
Enter the burst time:3

enter the details of process 3
Enter the process name:p2
Enter the arrival time:3
Enter the burst time:5

enter the details of process 4
Enter the process name:p3
Enter the arrival time:20
Enter the burst time:3

Enter the time quantum:2
Name        AT        BT        TT        WT
p0          0        4        6        2
p1          2        3        7        4
p2          3        5        9        4
p3            20        3        3        0

Gantt chart
-----------------------------------------------------------------------------------
|p0        |p1        |p0        |p2        |p1        |p2        |idle        |p3        |
-----------------------------------------------------------------------------------
0        2        4        6        8        9        12            20        23        
Average waiting time = 2.500000
Average turnaround time = 6.250000