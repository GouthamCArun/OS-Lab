#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int comp;
}p[10];
void sort (struct process p[],int n)
{
    int i,j;
    struct process temp;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (p[j].bt>p[j+1].bt)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int shortest(struct process p[],int n,int time)
{
    int min=9999;int shortind=-1;
    for (int i=0;i<n;i++)
    {
        if (p[i].at<=time && p[i].comp!=1)
        {
            if (p[i].bt<min)
            {
                min=p[i].bt;
                shortind=i;
            }
        }
    }
    return shortind;


}
void sjf(struct process p[],int n)
{
    int time=0,ttat=0,twt=0,shortindex=-1,completed=0;
    while(completed<n)
    {
        shortindex=shortest(p,n,time);
        while(shortindex==-1)
        {
            time++;
            shortindex=shortest(p,n,time);
        }
        
        time=time+p[shortindex].bt;
        p[shortindex].ct=time;
        p[shortindex].tat=p[shortindex].ct-p[shortindex].at;
        p[shortindex].wt=p[shortindex].tat-p[shortindex].bt;
        ttat=ttat+p[shortindex].tat;
        twt=twt+p[shortindex].wt;
        completed+=1;
    }
    printf("avg tat=%f\navg wt=%f\n",(float)ttat/n,(float)twt/n);
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
    }
    sort(p,n);
    sjf(p,n);
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
}