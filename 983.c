#include <stdio.h>

#define min(a,b)  a<b?a:b

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int f[daysSize],i;
    f[0]=costs[0];
    for(i=1;i<daysSize;i++){
        f[i]=f[i-1]+costs[0];
        int j;
        for(j=i-1;j>=0&&days[i]-days[j]<=7;j--){
            f[i]=min(f[i],f[i-1]+costs[1]);
        }
        for(;j>=0&&days[i]-days[j]<=30;j--){
            f[i]=min(f[i],f[i-1]+costs[2]);
        }
    }
    return f[daysSize-1];
}

int main(){
    int daysSize=6;
    int days[daysSize]={1,4,6,7,8,20};
    int costs[3]={2,7,15};
    printf("%d",mincostTickets(days,daysSize,costs,3));
}