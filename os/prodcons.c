#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex,full,empty;
int pro[50],con[50],buffer[5],item=0,put=0,get=0,gitem;

void *producer(void *arg)
{
  do
  {
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[put%5] = item;
    printf("Producer %d produced %d , buffer[%d] : %d\n", (*(int *)arg), item, put%5, item);
    item++;
    put++;
    sem_post(&mutex);
    sem_post(&full);
    sleep(3);
  }while(put<5);
}

void *consumer(void *arg)
{
  do
  {
    sem_wait(&full);
    sem_wait(&mutex);
    gitem = buffer[get%5];
    printf("Consumer %d consumed %d , buffer[%d] : %d\n", (*(int *)arg), gitem, get%5, gitem);
    get++;
    sem_post(&mutex);
    sem_post(&empty);
    sleep(2);
  }while(get<5);
}

void main()
{
  pthread_t a[10],b[10];
  
  int p,c,j,k;
  
  sem_init(&mutex,0,1);
  sem_init(&full,0,0);
  sem_init(&empty,0,5);
  
  printf("Enter the no of producers : ");
  scanf("%d",&p);
  printf("Enter the no of consumers : ");
  scanf("%d",&c);
  
  for(j=0;j<p;j++)
  {
    pro[j] = j;
    pthread_create(&a[j],NULL,producer,&pro[j]);
  }
  
  for(k=0;k<p;k++)
  {
    con[k] = k;
    pthread_create(&b[k],NULL,consumer,&con[k]);
  }
  
  for(j=0;j<p;j++)
  {
    pthread_join(a[j],NULL);
  }
  
  for(k=0;k<c;k++)
  {
    pthread_join(b[k],NULL);
  }
}
