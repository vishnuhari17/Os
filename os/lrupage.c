#include<stdio.h>
int frames[20],n_frame,time[20],counter=0;

int search(int value)
{
  for(int i=0;i<n_frame;i++)
  {
    if(value==frames[i])
    {
      time[i] = ++counter;
      return 1;
    }
  }
  return 0;
} 

int findlru()
{
  int min = time[0],index=0;
  for(int i=0;i<n_frame;i++)
  {
    if(time[i]<min)
    {
      min = time[i];
      index = i;
    }
  }
  return index;
}

void main()
{
  int n_page,i,page_fault=0,pages[50],next=0;
  printf("Enter the no of pages : ");
  scanf("%d",&n_page);
  printf("Enter the pages : \n");
  for(i=0;i<n_page;i++)
  {
    scanf("%d",&pages[i]);
  }
  printf("Enter the no of frames : ");
  scanf("%d",&n_frame);
  for(i=0;i<n_frame;i++)
  {
    frames[i] = -1;
  }
  for(i=0;i<n_page;i++)
  {
    if(search(pages[i])==1)
    {
      printf("Hit %d\n",pages[i]);
    }
    else
    {
      printf("Miss %d\n",pages[i]);
      int lru = findlru();
      frames[lru] = pages[i];
      time[lru] = ++counter;
      page_fault++;
    }
    for(int j=0;j<n_frame;j++)
    {
      printf("%d\t",frames[j]);
    }
    printf("\n");
  }
  printf("Page faults : %d",page_fault);
}
      

