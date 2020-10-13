#include<stdio.h>
#include<stdbool.h>

bool canJump(int* nums, int numsSize){
    int i;
    if(numsSize==1)
        return true;
    for(i=numsSize-2;i>=0;i--){
        if(nums[i]>=numsSize-i-1){
            return canJump(nums,i+1);
        }
    }
    return false;
}


int main(){
    int nums[1]={0};
    int numsSize=1;
    bool a=canJump(nums,numsSize);
    printf("%d",a);
}
