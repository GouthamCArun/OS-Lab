# include <stdio.h>
# include <stdlib.h>

void main()
{
    int rq[100];
    int i,n,head,index;
    int size,move;
    int total_head_count=0;
    printf("enter no.of requests");
    scanf("%d",&n);
    printf("enter the requests");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("enter the head position");
    scanf("%d",&head);
    printf("enter the size of disk");
    scanf("%d",&size);
    printf("enter the movement of disk");
    scanf("%d",&move);

    for(i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (rq[j]>rq[j+1])
            {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
    if (head<rq[i])
    {
        index=i;
        break;
    }
    }
    printf("index=%d",index);
    if (move==1)
    {
        for(i=index;i<n;i++)
        {
            total_head_count+=abs(rq[i]-head);
            head=rq[i];
        }
        total_head_count+=abs(size-1-head);

        total_head_count+=abs(size-1-rq[0]);
        printf("total head count%d",total_head_count);

    }
    else{
        for(i=index-1;i>=0;i--)
        {
            total_head_count+=abs(rq[i]-head);
            head=rq[i];
        }
        total_head_count+=abs(0-head);
        total_head_count+=abs(0-rq[n-1]);
        printf("total head count%d",total_head_count);
    }


}