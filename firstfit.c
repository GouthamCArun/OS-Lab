#include <stdio.h>

void main()
{
    int i,n,m;
    printf("enter the number of blocks");
    scanf("%d",&m);
    printf("enter the number of processes");
    scanf("%d",&n);
    int block[m];
    int process[n];
    for (i=0;i<m;i++)
    {
        printf("enter the size of block %d: ",i+1);
        scanf("%d",&block[i]);
    }
    for (i=0;i<n;i++)
    {
        printf("enter the size of process %d: ",i+1);
        scanf("%d",&process[i]);
    }
    int allocation[n];
    for (i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for (i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (block[j]>process[i])
            {
                allocation[i]=j;
                block[j]-=process[i];
                break;
            }
        }
    }
    printf("p_no\tp_size\tb_no\n");
    for (i=0;i<n;i++)
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