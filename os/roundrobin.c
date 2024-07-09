#include<stdio.h>
#include<string.h>

struct process
{
  char pname[10];
  int at,bt,ct,tt,wt,rt,status;
}p[50];

struct ghant
{
  char gname[10];
  int st,ct;
}g[50];

int queue[50],front = -1,rear = -1;

void enqueue(int value)
{
  if(front==-1)
  {
    front++;
  }
  queue[++rear] = value;
}

int dequeue()
{
  int a = queue[front];
  if(front==rear)
  {
    front = rear = -1;
  }
  else
  {
    front++;
  }
  return a;
}

void main()
{
  int n,i,time_quantum,p_index,g_index = 0,idle=0;
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
    p[i].rt = p[i].bt;
    p[i].status = 0;
  }
  printf("Enter the time quantum : ");
  scanf("%d",&time_quantum);
  int time_elapsed = 0;
  int process_completed = 0;
  while(process_completed<n)
  {
    printf("inside while\n");
    for(i=0;i<n;i++)
    {
      if(p[i].status == 0 && p[i].at <= time_elapsed)
      {
        enqueue(i);
        p[i].status = 1;
      }
    }
    if (front == -1)
    {
      if(idle==0)
      {
        strcpy(g[g_index].gname,"idle");
        g[g_index].st = time_elapsed;
        idle = 1;
      }
      time_elapsed++;
    }
    else
    {
      if(idle==1)
      {
        g[g_index].ct = time_elapsed;
        idle = 0;
        g_index++;
      }
      p_index = dequeue();
      if(p[p_index].rt<=time_quantum)
      {
        strcpy(g[g_index].gname,p[p_index].pname);
        g[g_index].st = time_elapsed;
        time_elapsed += p[p_index].rt;
        p[p_index].status = 2;
        g[g_index].ct = time_elapsed;
        p[p_index].ct = g[g_index].ct;
        p[p_index].tt = p[p_index].ct - p[p_index].at;
        p[p_index].wt = p[p_index].tt - p[p_index].bt;
        process_completed++;
        g_index++;
      }
      else
      {
        strcpy(g[g_index].gname,p[p_index].pname);
        g[g_index].st = time_elapsed;
        time_elapsed += time_quantum;
        g[g_index].ct = time_elapsed;
        p[p_index].rt -= time_quantum;
        g_index++;
        for(i=0;i<n;i++)
        {
          if(p[i].status == 0 && p[i].at <= time_elapsed)
          {
            enqueue(i);
            p[i].status = 1;
          }
        }
        enqueue(p_index);     
      }
      
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
