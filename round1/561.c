#include<stdio.h>

int main()
{
    int nums[4] = {1,4,3,2};
    int numsSize=4;
    int n[20001]={0},i,j=1,res;
    for(i=0;i<numsSize;i++){
        n[nums[i]+10000]++;
    }
    for(i=0;i<20001;i++){
        if(n[i]){
            if(j%2==1){
                res+=(i-10000);
                n[i]--;
            }   
            i--;
            j++;
        }
    }


}