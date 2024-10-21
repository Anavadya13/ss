#include<stdio.h>
#include<stdlib.h>
int main() {
    int n,i,RQ[100],initial,disk_size,TotalHeadMovement=0;
    printf("Number of requests:");
    scanf("%d",&n);
    printf("Enter request sequence:");
    for(i=0;i<n;i++) {
        scanf("%d",&RQ[i]);    }
    printf("Enter initial head position:");
    scanf("%d",&initial);
    printf("Enter disk size:");
    scanf("%d",&disk_size);
    for(i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(RQ[j]>RQ[j+1]) {
                int temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;       }    }    }
    int current_position=initial;
    for(i=0;i<n;i++) {
        if(RQ[i]>=initial) {
            TotalHeadMovement+=abs(RQ[i]-current_position);
              current_position=RQ[i];        }    }
  if(current_position!=disk_size-1) {
        TotalHeadMovement+=abs((disk_size-1)-current_position);
        current_position=0;
        TotalHeadMovement+=(disk_size-1);    }
    for(i=0;i<n;i++) {
        if(RQ[i]<initial) {
            TotalHeadMovement+=abs(RQ[i]-current_position);
            current_position=RQ[i];        }    }
    printf("Total Head Movement is %d\n",TotalHeadMovement);
    return 0;}	
