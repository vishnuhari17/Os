#include<stdio.h>
void main()
{
        int i,j,n,num,track[50],head_mov=0;
        printf("enter the number of tracks: ");
        scanf("%d",&n);
        printf("enter the tracks\n");
        for(i=1;i<=n;i++)
        {
                scanf("%d",&track[i]);
        }
        printf("enter the head start:");
        scanf("%d",&num);
        printf("\n");
        track[0]=num;
        for(i=0;i<n;i++)
        {
                printf("%d is traversed\n",track[i+1]);
                if(track[i+1]>track[i])
                {
                        head_mov+=(track[i+1]-track[i]);
                }
                else
                {
                        head_mov+=(track[i]-track[i+1]);
                }
        }
        printf("\n");
        for(i=1;i<n-1;i++)
                printf("%d->",track[i]);
        printf("%d",track[i]);
        printf("\n");
        printf("\ntotal head movement: %d",head_mov);
}