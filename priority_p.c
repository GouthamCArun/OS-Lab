#include <stdio.h>
struct process{
    int pid;int at;int bt;int ct;int tat;int wt;int comp;int prio;int rt;
}p[10];
int gethigh(struct process p[],int n,int time)
{
    int max=999;int highind=-1;
    for (int i=0;i<n;i++)
    {
        if (p[i].at<=time && p[i].comp!=1 )
        {
            if (p[i].prio<max)
            {
                max=p[i].prio;
                highind=i;
            }
        }
   
    }
    return highind;

}
void pp(struct process p[],int n)
{
    int time=0,ttat=0,twt=0,highindex=-1,completed=0;
    while(completed<n)
    {
        highindex=gethigh(p,n,time);
        while(highindex==-1)
        {
            time++;
            highindex=gethigh(p,n,time);
        }
        p[highindex].rt--;
        time++;
        if (p[highindex].rt==0)
        {
            p[highindex].comp=1;
            p[highindex].ct=time;
            p[highindex].tat=p[highindex].ct-p[highindex].at;
            p[highindex].wt=p[highindex].tat-p[highindex].bt;
            ttat=ttat+p[highindex].tat;
            twt=twt+p[highindex].wt;
            completed++;
        }
    }
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("avg tat=%f\n",ttat/(float)n);
    printf("avg wt=%f\n",twt/(float)n);
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
        p[i].rt=p[i].bt;
        p[i].comp=0;
        printf("Enter the priority of process %d: ",i+1);
        scanf("%d",&p[i].prio);
    }
    
    pp(p,n);
    printf("P\tAt\tBt\tct\ttat\twt\n");
    for(i=0;i<n;i++)
    {
        
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        printf("\n");
    }
    


}