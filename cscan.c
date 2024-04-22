#include<stdio.h>
void main()
{
    int tr[30],i,j,t,cur,s=0,n,temp;
    printf("C SCAN DISK SCHEDULING ALGORITHM\n");
    printf("Enter the number of tracks\n");
    scanf("%d",&t);
    printf("Enter current head position\n");
    scanf("%d",&cur);
    printf("Enter the tracks\n");
    for(i=2;i<=t+1;i++)
            scanf("%d",&tr[i]);
    printf("The given pages are:\n");
    for(i=2;i<=t+1;i++)
            printf("%d\t",tr[i]);
    printf("\n");
    tr[0]=0;
    tr[1]=cur;
    tr[t+2]=199;
    n=t+3;
    for(i=0;i<(n-1);i++)
    {
            for(j=0;j<(n-i-1);j++)
            {
                    if(tr[j]>tr[j+1])
                    {
                            temp=tr[j];
                            tr[j]=tr[j+1];
                            tr[j+1]=temp;
                    }
            }
    }
    for(i=0;i<n;i++)
    {
            if(tr[i]==cur)
                    break;
    }
    printf("Head movements:\n");
    if((cur-0)<(199-cur))
    {
            for(j=i;j>0;j--)
            {
                    s=s+(tr[j]-tr[j-1]);
                    printf("%d-->",tr[j]);
            }
            printf("0-->");
            s=s+(199-0);
            for(j=n-1;j>i+1;j--)
            {
                    s=s+(tr[j]-tr[j-1]);
                    printf("%d-->",tr[j]);
            }
            printf("%d",tr[i+1]);
            printf("\nTotal head movements: %d",s);
            printf("\n");
    }
    else if((cur-0)>(199-cur))
    {
            for(j=i;j<n-1;j++)
            {
                    s=s+(tr[j+1]-tr[j]);
                    printf("%d-->",tr[j]);
            }
            printf("199-->0-->");
            s=s+(199-0);
            for(j=1;j<i;j++)
            {
                    s=s+(tr[j]-tr[j-1]);
                    printf("%d-->",tr[j]);
            }
            printf("\nTotal head movements: %d",s);
            printf("\n");
    } 
}