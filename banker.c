#include<stdio.h>
void main()
{
        int i,j,m,n,alloc[10][10],max[10][10],avail[10],need[10][10],p,in[10],f=0,status[10],flag=0,k,count=0,seq[10],num=0;
        printf("Enter the number of processes:");
        scanf("%d",&m);
        printf("Enter the number of resources:");
        scanf("%d",&n);
        printf("Enter the allocation matrix\n");
        for(i=0;i<m;i++)
                status[i]=0;
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&alloc[i][j]);
                }
        }
        printf("Enter the maximum matrix\n");
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&max[i][j]);
                }
        }
        printf("Enter the available matrix\n");
        for(j=0;j<n;j++)
        {
                scanf("%d",&avail[j]);
        }
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        need[i][j]=max[i][j]-alloc[i][j];
                }
        }
        printf("P\tAllocation   Max       Need     Available\n");
        for(i=0;i<m;i++)
        {
                printf("P%d\t",i);
                for(j=0;j<n;j++)
                {
                        printf("%d  ",alloc[i][j]);
                }
                printf("  ");
                for(j=0;j<n;j++)
                {
                        printf("%d  ",max[i][j]);
                }
                printf("  ");
                for(j=0;j<n;j++)
                {
                        printf("%d  ",need[i][j]);
                }
                printf("  ");
                if(i==0)
                {
                        for(j=0;j<n;j++)
                        {
                                printf("%d  ",avail[j]);
                        }

                }
                printf("\n");        
        }
        printf("Enter the process that is requesting\n");
        scanf("%d",&p);
        printf("Enter the number of requesting resources\n");
        for(i=0;i<n;i++)
                scanf("%d",&in[i]);
        for(i=0;i<n;i++)
        {
                if(in[i]>avail[i] && in[i]>need[p][i])
                {
                        f++;
                        break;
                }
        }
        if(f==0)
        {
                for(i=0;i<n;i++)
                {
                        avail[i]-=in[i];
                        need[p][i]-=in[i];
                        alloc[p][i]+=in[i];
                }
        }
        printf("P\tAllocation   Max       Need     Available\n");
        for(i=0;i<m;i++)
        {
                printf("P%d\t",i);
                for(j=0;j<n;j++)
                {
                        printf("%d  ",alloc[i][j]);
                }
                printf("  ");
                for(j=0;j<n;j++)
                {
                        printf("%d  ",max[i][j]);
                }
                printf("  ");
                for(j=0;j<n;j++)
                {
                        printf("%d  ",need[i][j]);
                }
                printf("  ");
                if(i==0)
                {
                        for(j=0;j<n;j++)
                        {
                                printf("%d  ",avail[j]);
                        }

                }
                printf("\n");        
        }
        for(i=0;i<m;i++)
        {        
                for(j=0;j<m;j++)
                {
                        if(status[j]==0)
                        {
                                flag=0;
                                for(k=0;k<n;k++)
                                {
                                        if(avail[k]<need[j][k])
                                        {
                                                flag++;
                                                break;
                                        }
                                }
                                if(flag==0)
                                {
                                        printf("the process %d is visited\n",j);
                                        seq[num]=j;
                                        num++;
                                        status[j]=1;
                                        for(k=0;k<n;k++)
                                        {
                                                avail[k]=avail[k]+alloc[j][k];
                                        }
                                        count++;
                                }
                        }
                }
        }
        if(count!=m)
        {
                printf("\nDEADLOCK Condition\n");
        }
        else
        {
                printf("\nThis is a Safe Sequence\n");
                for(k=0;k<m-1;k++)
                {
                        printf("P%d->",seq[k]);
                }
                printf("P%d",seq[k]);
        }
}




Enter the number of processes:5  
Enter the number of resources:3
Enter the allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the maximum matrix
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the available matrix
3 3 2
P        Allocation   Max       Need     Available
P0        0  1  0    7  5  3    7  4  3    3  3  2  
P1        2  0  0    3  2  2    1  2  2    
P2        3  0  2    9  0  2    6  0  0    
P3        2  1  1    2  2  2    0  1  1    
P4        0  0  2    4  3  3    4  3  1    
Enter the process that is requesting
1 
Enter the number of requesting resources
1 0 2
P        Allocation   Max       Need     Available
P0        0  1  0    7  5  3    7  4  3    2  3  0  
P1        3  0  2    3  2  2    0  2  0    
P2        3  0  2    9  0  2    6  0  0    
P3        2  1  1    2  2  2    0  1  1    
P4        0  0  2    4  3  3    4  3  1    
the process 1 is visited
the process 3 is visited
the process 4 is visited
the process 0 is visited
the process 2 is visited

This is a Safe Sequence
P1->P3->P4->P0->P2