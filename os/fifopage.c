#include<stdio.h>
int frames[20],n_frame;

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
      frames[next] = pages[i];
      next = (next + 1) % n_frame;
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
      

