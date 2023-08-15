#include <stdio.h>

void main()
{
    int i,n,f;
    prinf("enter the number of entries");
    scanf("%d",&n);
    int a[10];
    printf("enter the entries");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n;i<10;i++)
    {
        a[i]=-1;
    }
    printf("enter no.of frames");
    scanf("%d",&f);
    
}