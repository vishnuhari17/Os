#include<stdio.h>
#include<string.h>
#define MAX 20
void main()
{
  int n_process,n_res,i,j,k,allocated[MAX][MAX],max[MAX][MAX],need[MAX][MAX],available[MAX],p,req[MAX],count=0,f;
  printf("Enter the no of process : ");
  scanf("%d",&n_process);
  printf("Enter the no of resources : ");
  scanf("%d",&n_res);
  printf("Enter the Allocation table\n");
  for(i=0;i<n_process;i++)
  {
    printf("Enter the allocation details of process %d: \n",i);
    for(j=0;j<n_res;j++)
    {
      scanf("%d",&allocated[i][j]);
    }
  }
  printf("Enter the Maximum table\n");
  for(i=0;i<n_process;i++)
  {
    printf("Enter the Max details of process %d: \n",i);
    for(j=0;j<n_res;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
  
  printf("Enter the details of available resources : \n");
  for(i=0;i<n_res;i++)
  { 
    scanf("%d",&available[i]);
  }
  
  for(i=0;i<n_process;i++)
  {
    for(j=0;j<n_res;j++)
    {
      need[i][j] = max[i][j] - allocated[i][j];
    }
  }
  
  printf("The current allocation table is : \n");
  printf("Allocated\t\tMaximum\t\t\tNeed\t\t\tAvailable\n");
  for(i=0;i<n_process;i++)
  {
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",allocated[i][j]);
    }
    printf("\t\t");
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",max[i][j]);
    }
    printf("\t\t");
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",need[i][j]);
    }
    printf("\t\t");
    if(i==0)
    {
      for(j=0;j<n_res;j++)
      {
        printf("%d  ",available[j]);
      }
    }
    printf("\n");
  }
  
  printf("Enter the process which is requesting : ");
  scanf("%d",&p);
  printf("Enter the request : ");
  for(i=0;i<n_res;i++)
  {
    scanf("%d",&req[i]);
  }
  int f=0;
  for(i=0;i<n_res;i++)
  {
    if(req[i] > available[i] || req[i] > need[p][i])
    {
      f=1;
      break;
    }
  }
  if(f==0)
  {
    printf("The request was sucessfull\n");
    for(i=0;i<n_res;i++)
    {
      available[i] -= req[i];
      need[p][i] -= req[i];
      allocated[p][i] += req[i];
    }
    printf("Modified allocation table : \n");
    printf("Allocated\t\tMaximum\t\t\tNeed\t\t\tAvailable\n");
  for(i=0;i<n_process;i++)
  {
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",allocated[i][j]);
    }
    printf("\t\t");
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",max[i][j]);
    }
    printf("\t\t");
    for(j=0;j<n_res;j++)
    {
      printf("%d  ",need[i][j]);
    }
    printf("\t\t");
    if(i==0)
    {
      for(j=0;j<n_res;j++)
      {
        printf("%d  ",available[j]);
      }
    }
    printf("\n");
  }
    //safetysequence
    int finish[MAX],w[MAX];
    int c = 0,f;
    for(i=0;i<n_process;i++)
    {
      finish[i] = 0;
    }
    for(i=0;i<n_process;i++)
    {
      for(j=0;j<n_process;j++)
      {
        f=0;
        if(finish[j] == 0)
        {
          for(k=0;k<n_res;k++)
          {
            if(available[k] < need[j][k])
            {
              f=1;
              break;
            }
          }
          if(f==0)
          {
            printf("Process %d executed\n",j);
            w[c]=j;
            c++;
            finish[j]=1;
            count++;
            printf("Available : ");
            for(k=0;k<n_res;k++)
            {
              available[k] += allocated[j][k];
              printf("%d ", available[k]);
            }
          }
        }
      }
    }
    if(count==n_process)
    {
      printf("Deadlock free\n");
      printf("Safetysequence : ");
      printf("p%d",w[0]);
      for(i=1;i<c;i++)
      {
        printf(" -> p%d",w[i]);
      }
    }
    else
    {
      printf("Deadlock\n");
    }
  }
  else
  {
    printf("Request failed");
  }
    
  
}
        
  
