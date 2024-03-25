#include<stdio.h>
#include<string.h>

struct process
{	
	int at,bt,wt,tt;
	char name[10];
}p[10],temp;

struct gantt
{	
	int st,ct;
	char name[10];
}g[10];

void main()
{	
	int n,i,j,pt=0,time_elapsed=0,gt=0;
	float wait = 0,turn=0;
	printf("Enter the no of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details of process\n");
		printf("Name : ");
		scanf("%s",p[i].name);
		printf("Arrival time : ");
		scanf("%d",&p[i].at);
		printf("Burst time : ");
		scanf("%d",&p[i].bt);
	}
	printf("The details of the processes before sort are \n");
	printf("-----------------------\n");
	printf("Name\tAT\tBt\n");
	printf("-----------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\n",p[i].name,p[i].at,p[i].bt);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{	
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	printf("The details of the processes after sort are \n");
	printf("-----------------------\n");
	printf("Name\tAT\tBt\n");
	printf("-----------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\n",p[i].name,p[i].at,p[i].bt);
	}
	while(pt<n)
	{	
		if(time_elapsed>=p[pt].at)
		{
			strcpy(g[gt].name,p[pt].name);
			g[gt].st = time_elapsed;
			time_elapsed += p[pt].bt;
			g[gt].ct = time_elapsed;
			p[pt].wt = g[gt].st - p[pt].at;
			p[pt].tt = g[gt].ct - p[pt].at;
			gt++;
			pt++;
		}
		else
		{
			strcpy(g[gt].name,"idle");
			g[gt].st=time_elapsed;
			g[gt].ct=p[pt].at;
			time_elapsed=g[gt].ct;
			gt++;
		}
	}
	printf("The details of the processes after gantt are \n");
	printf("---------------------------------\n");
	printf("Name\tAT\tBt\tWt\tTt\n");
	printf("---------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		wait=wait+p[i].wt;
		turn=turn+p[i].tt;
	}
	
	printf("---------------------------------------------------------\n");
	printf("|");
	for(i=0;i<gt;i++)
	{
		printf("%s\t|",g[i].name);
	}
	printf("\n---------------------------------------------------------\n");
	printf("%d\t",g[gt].st);
	for(i=0;i<gt;i++)
	{
		printf("%d\t",g[i].ct);
	}
	printf("\n");
	printf("Average waiting time = %f\n",wait/n);
	printf("Average turnaround time = %f\n",turn/n);
			
		
	
}

