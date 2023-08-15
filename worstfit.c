#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m,n;
    printf("enter no.of blocks");
    scanf("%d",&m);
    printf("enter no.of processes");
    scanf("%d",&n);
    int block[m];
    int process[n];
    for (int i=0;i<m;i++)
    {
        printf("enter the size of block %d: ",i+1);
        scanf("%d",&block[i]);
    }
    for (int i=0;i<n;i++)
    {
        printf("enter the size of process %d: ",i+1);
        scanf("%d",&process[i]);
    }
    int allocation[n];
    int bestindex;
    for (int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for (int i=0;i<n;i++)
    {
        bestindex=-1;
        for(int j=0;j<m;j++)
        {
            
            if (block[j]>process[i])
            {
                if(bestindex==-1)
                {
                    bestindex=j;
                
                }
                else if(block[bestindex]<block[j])
                {
                    bestindex=j;
                }
            }
        }
        if (bestindex!=-1)
        {
            allocation[i]=bestindex;
            block[bestindex]-=process[i];
        }
    }
    printf("p_no\tp_size\tb_no\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,process[i]);
        if (allocation[i]!=-1)
        {
            printf("%d\n",allocation[i]+1);
        }
        else
        {
            printf("not allocated\n");
        }
    }

}


