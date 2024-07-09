#include<stdio.h>

struct process
{
  int id,size,block_no;
}p[20];

struct block
{
  int id,size,alloc;
}b[20];

void main()
{
  int n_block,n_process,i,j;
  printf("Enter the no of blocks : ");
  scanf("%d",&n_block);
  for(i=0;i<n_block;i++)
  {
    printf("Enter the size of block %d : ",i+1);
    scanf("%d",&b[i].size);
    b[i].id = i+1;
    b[i].alloc = -1;
  }
  printf("Enter the no of Process : ");
  scanf("%d",&n_process);
  for(i=0;i<n_process;i++)
  {
    printf("Enter the size of process %d : ",i+1);
    scanf("%d",&p[i].size);
    p[i].id = i+1;
    p[i].block_no = -1;
  }
  
  for(i=0;i<n_process;i++)
  {
    for(j=0;j<n_block;j++)
    {
      if(b[j].alloc == -1 && p[i].size <= b[j].size)
      {
        p[i].block_no = b[j].id;
        b[j].alloc = 1;
        break;
      }
    }
  }
  printf("P-No\tB-No\n");
  for(i=0;i<n_process;i++)
  {
    printf("%d\t%d\n",p[i].id,p[i].block_no);
  }
}
