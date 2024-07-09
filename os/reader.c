#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>

void main()
{
  int shmid = shmget(1718,1024,0666);
  if(shmid == -1)
  {
    printf("No data found\n");
  }
  else
  {
    void *mem = shmat(shmid,NULL,0);
    int num = atoi(mem);
    int square = num * num;
    int digit = square%10;
    if(digit==num)
    {
      printf("The number is Automorphic\n");
    }
    else
    {
      printf("The number is Not Automorphic\n");
    }
  }
}
