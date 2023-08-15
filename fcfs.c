#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[10];

void sort(struct process p[],int n)
{
    int i,j;
    struct process temp;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

            }
        }
    }
}
void waitingtime(struct process p[],int n)
{
    int i;
    p[0].wt=0;
    for (i=1;i<n;i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;
    }
}
void turnaroundtime(struct process p[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        p[i].tat=p[i].wt+p[i].bt;
    }
}
void completiontime(struct process p[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        p[i].ct=p[i].tat+p[i].at;
    }
}
void fcfs(struct process p[],int n)
{
    int time=0,ttat=0,twt=0;
    for(int i=0;i<n;i++)
    {
        while(time<p[i].at)
        {
            time++;
        }
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        ttat+=p[i].tat;
        twt+=p[i].wt;

    }
    printf("Average turnaround time: %f\n",(float)ttat/(float)n);
    printf("Average waiting time: %f\n",(float)twt/(float)n);
}
void main()
{
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].bt);
    }
    sort(p,n);
    fcfs(p,n);
    printf("P\tAt\tBt\tct\ttat\twt\n");
    for(i=0;i<n;i++)
    {
        
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        printf("\n");
    }
    


}
