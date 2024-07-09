#include<stdio.h>
int frames[20],n_frame,n_page,pages[50];

int search(int value)
{
  for(int i=0;i<n_frame;i++)
  {
    if(value==frames[i])
    {
      return 1;
    }
  }
  return 0;
} 

int findoptimal(int current_index)
{
  int farthest = current_index,found,index=0;
  for(int i=0;i<n_frame;i++)
  {
    found = 0;
    for(int j=current_index+1;j<n_page;j++)
    {
      if(frames[i] == pages[j])
      {
        found = 1;
        if(j>farthest)
        {
          farthest = j;
          break;
        }
      }
    }
    if(found == 0)
    {
      return i;
    }
  }
  return farthest;
}

void main()
{
  int i,page_fault=0,next=0;
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
      int optimal = findoptimal(i);
      frames[optimal] = pages[i];
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
      

