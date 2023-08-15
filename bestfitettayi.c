#include<stdio.h>
#include<stdlib.h>
 void main(){
    int m,n;
    printf("Enter the number of block and process size\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int block[m];
    int process[n];
    int bestidx;
    printf("Enter the size of blocks\n");
    for(int i=0;i<m;i++){
        scanf("%d",&block[i]);
 }
    printf("Enter the size of process\n");
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
 }
 int allocation[n];
 for(int i=0;i<n;i++){
 allocation[i]=-1;
 }
 for(int i=0;i<n;i++){
    bestidx=-1;
    for(int j=0;j<m;j++){
        if(block[j]>=process[i]){
        
        if(bestidx==-1){
            bestidx=j;
        }
        else if(block[bestidx]>block[j]){
            bestidx=j;
        }
    }
    }
    
        if(bestidx!=-1){
            allocation[i]=bestidx;
            block[bestidx]-=process[i];
            
        }

    }
    printf("Process no\t\tprocess size\t\tblock no\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t",i+1);
        printf("%d\t\t",process[i]);
        if(allocation[i]!=-1){
            printf("%d",allocation[i]+1);
        }else{
            printf("not allocated");
        }
 printf("\n");
    }

    

    
 }