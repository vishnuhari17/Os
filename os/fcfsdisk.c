#include<stdio.h>

void main()
{
  int n,i,process[50],head,movement=0,initial,final;
  printf("Enter the no of process : ");
  scanf("%d",&n);
  printf("Enter the processes : \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&process[i]);
  }
  printf("Enter the head position : ");
  scanf("%d",&head);
  initial = head;
  for(i=0;i<n;i++)
  {
    final = process[i];
    printf("Process %d served\n",final);
    movement += (final>initial)?(final-initial):(initial-final);
    initial = final;
  }
  printf("The total head movement was : %d\n",movement);
}
