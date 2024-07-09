#include<stdio.h>

void main()
{
  int n,i,j,process[50],head,movement=0,initial,final,start,end,direction=1,temp;
  printf("Enter the no of process : ");
  scanf("%d",&n);
  printf("Enter the processes : \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&process[i]);
  }
  printf("Enter the head position : ");
  scanf("%d",&head);
  printf("Enter the size of the disk");
  scanf("%d",&end);
  start = 0;
  if(head<(end-head))
  {
    direction = 0;
    //move to left
  }
  initial = head;
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(process[j]>process[j+1])
      {
        temp = process[j];
        process[j] = process[j+1];
        process[j+1] = temp;
      }
    }
  }
  
  printf("The processes are :");
  for(i=0;i<n;i++)
  {
    printf("%d\t",process[i]);
  }
  printf("\n");
  
  if(direction==1)
  {
    //move to right
    for(i=0;i<n;i++)
    {
      if(process[i]>head)
      {
        break;
      }
    }
    for(;i<n;i++)
    {
      final = process[i];
      printf("Process %d served\n",final);
      movement += (final>initial)?(final-initial):(initial-final);
      initial = final;
    }
    if(i==n)
    {
      movement += end - final;
      initial = end;
    }
    for(i=n-1;i>=0;i--)
    {
      if(process[i]<head)
      {
        break;
      }
    }
    for(;i>=0;i--)
    {
      final = process[i];
      printf("Process %d served\n",final);
      movement += (final>initial)?(final-initial):(initial-final);
      initial = final;
    }
  }
  else
  {
    for(i=n-1;i>=0;i--)
    {
      if(process[i]<head)
      {
        printf("%d",process[i]);
        break;
      }
    }
    for(;i>=0;i--)
    {
      final = process[i];
      printf("Process %d served\n",final);
      movement += (final>initial)?(final-initial):(initial-final);
      initial = final;
    }
    if(i==-1)
    {
      movement += final - start;
      initial = start;
    }
    for(i=0;i<n;i++)
    {
      if(process[i]>head)
      {
        break;
      }
    }
    for(;i<n;i++)
    {
      final = process[i];
      printf("Process %d served\n",final);
      movement += (final>initial)?(final-initial):(initial-final);
      initial = final;
    }
  }
  printf("The total head movement was : %d\n",movement);
}
