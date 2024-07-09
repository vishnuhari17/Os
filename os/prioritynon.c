#include<stdio.h>
#include<string.h>

struct process
{
  char pname[20];
  int at,bt,pt,ct,tt,wt,status;
} p[20];

struct gantt
{
  char gname[20];
  int st,ct;
} g[50];

void main()
{
  int n,i,p_index,g_index=0,min,idle;
  printf("Enter the no of process : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the name of the process : ");
    scanf("%s",&p[i].pname);
    printf("Enter the arrival time : ");
    scanf("%d",&p[i].at);
    printf("Enter the burst time : ");
    scanf("%d",&p[i].bt);
    printf("Enter the priority : ");
    scanf("%d",&p[i].pt);
    p[i].status = 0;
  }
  int time_elapsed = 0;
  int process_completed = 0;
  while(process_completed < n)
  {
    min = 1000;
    p_index=500;
    for(i=0;i<n;i++)
    {
      if(p[i].at <= time_elapsed && p[i].pt < min && p[i].status == 0)
      {
        min = p[i].pt;
        p_index = i;
      }
    }
    if(min == 1000)
    {
      if(idle != 1)
      {
        strcpy(g[g_index].gname,"idle");
        g[g_index].st=time_elapsed;
        idle = 1;
      }
      time_elapsed += 1;
    }
    else
    {
      if(idle == 1)
      {
        g[g_index].ct = time_elapsed;
        idle = 0;
        g_index += 1;
      }
      strcpy(g[g_index].gname,p[p_index].pname);
      p[p_index].status = 1;
      g[g_index].st = time_elapsed;
      g[g_index].ct = time_elapsed + p[p_index].bt;
      p[p_index].ct = g[g_index].ct;
      p[p_index].tt = p[p_index].ct - p[p_index].at;
      p[p_index].wt = p[p_index].tt - p[p_index].bt;
      g_index += 1;
      process_completed += 1;
      time_elapsed += p[p_index].bt;
    }
  }
  
  printf("Gantt Chart\n");
  for(i=0;i<g_index;i++)
  {
    printf("%s\t|",g[i].gname);
  }
  printf("\n%d\t",g[0].st);
  for(i=0;i<g_index;i++)
  {
    printf("%d\t",g[i].ct);
  }
  printf("\nProcess table\n");
  printf("P-Name\tAT\tBT\tCT\tTT\tWT\n");
  for(i=0;i<n;i++)
  {
    printf("%s\t%d\t%d\t%d\t%d\t%d\n",p[i].pname,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
  }
  
  
}
    
