#include <stdio.h>
struct process{
    int pid;int at;int bt;int ct;int tat;int wt;int comp;int status;int rt;
}p[10];
int q[10],front=-1,rear=-1;

void enque(int q[],int k,int n)
{
    if (front==-1)
    {
        front=0;
    }
    rear=(rear+1)%n;
    q[rear]=k;
    printf("que is:");
    for(int i=front;i<=rear;i++)
    {
        
        printf("%d ",q[i]);
    }
    printf("\n");
}

int deque(int q[],int n)
{
    int temp;
    if (front==-1 && rear==-1)
    {
        return -1;
    }
    if (front=rear)
    {
        temp=q[front];
        front=-1;
        rear=-1;
    }
    else
    {
        temp=q[front];
        front=(front+1)%n;
    }
    return temp;
}

void insertele(int q[],int n,int time)
{
    for (int i=0;i<n;i++)
    {
        if (p[i].at<=time && p[i].status==0)
        {
            printf("insert ele time=%d\n",time);
            enque(q,i,n);
            p[i].status=1;
        }
        // enque(q,i,n);
    }
}

void RR(struct process p[],int n,int q[],int qt)
{
    int currentindex=-1,time=0,completed=0,ttat=0,twt=0;
    while (completed!=n)
    {
        insertele(q,n,0);
        currentindex=deque(q,n);
        while (currentindex==-1)
        {
            time++;
            insertele(q,n,time);
            currentindex=deque(q,n);
        };
        for (int i=0;i<qt;i++)
        {
            time++;
            p[currentindex].rt--;
            insertele(q,n,time);
            if (p[currentindex].rt==0)
            {
                break;
            }
        }
        if (p[currentindex].rt==0)
        {
            p[currentindex].ct=time;
            p[currentindex].tat=p[currentindex].ct-p[currentindex].at;
            p[currentindex].wt=p[currentindex].tat-p[currentindex].bt;
            p[currentindex].comp=1;
            ttat=ttat+p[currentindex].tat;
            twt=twt+p[currentindex].wt;
            completed++;
            printf("completed=%d\n",completed);
        }
        else
        {
            enque(q,currentindex,n);
        }
    }
    printf("avg tat is %f\n",(float)ttat/n);
    printf("avg wt is %f\n",(float)twt/n);
}
void main()
{
    int n,i;
    printf("enter no of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].status=0;
        p[i].rt=p[i].bt;
       
    }
        printf("pid\tat\tbt\tct\ttat\twt\trt\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    RR(p,n,q,2);
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
}