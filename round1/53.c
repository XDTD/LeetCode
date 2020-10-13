//¶¯Ì¬¹æ»®

#define max(a,b) a>b?a:b

int maxSubArray(int* nums, int numsSize) {
    int sum=0,i,res=nums[0];
    for(i=0;i<numsSize;i++){
        if(sum>0)
            sum+=nums[i];
        else
            sum=nums[i];
        res=max(res,sum);
    }
    return res;
}
