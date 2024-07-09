#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

void main()
{
  int shmid;
  char string[25];
  shmid = shmget(1718,1024,0666|IPC_CREAT);
  void *mem = shmat(shmid,NULL,0);
  printf("Enter the data to write : ");
  scanf("%s",&string);
  strcpy(mem,string);
}
