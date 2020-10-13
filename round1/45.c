#define min(a,b) a<b?a:b
#include<stdio.h>
/*
int jump(int* nums, int numsSize){
    int i,j,ans;
    if(numsSize==1)
        return 0;
    for(i=numsSize-1;i>=0;i--){
        if(numsSize-i-1<=nums[i])
            j=min(j,i);
    }
    return jump(nums,j+1)+1;
}

*/

int jump(int* nums, int numsSize){
    int end = 0;
    int maxPosition = 0;
    int steps = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        maxPosition = max(maxPosition, i + nums[i]);
        if (i == end) {
            end = maxPosition;
            steps++;
        }
    }
    return steps;
}


int main(){
    int nums[6]={2,4,2,1,1,1};
    int numsSize=6;
    printf("%d",jump(nums,numsSize));
}
