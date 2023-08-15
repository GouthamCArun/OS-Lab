#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i,n,head;
    int total_head_count=0;
    int rq[100];
    printf("enter no.of requests");
    scanf("%d",&n);
    printf("enter the requests");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("enter the head position");
    scanf("%d",&head);
     
    for(i=0;i<n;i++)
    {
        total_head_count+=abs(rq[i]-head);
        head=rq[i];
    }
    printf("total head count=%d",total_head_count);


}
