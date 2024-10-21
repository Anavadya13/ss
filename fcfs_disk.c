#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, RQ[100],initial, TotalHeadMoment=0;
    printf("no of req\n");
    scanf("%d",&n);
    printf("enter req seq\n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&RQ[i]);
    }
    printf("initial\n");
    scanf("%d",&initial);
    
    for(i=1;i<n;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    
    printf("Total Head Moment is %d \n",TotalHeadMoment);

} 
