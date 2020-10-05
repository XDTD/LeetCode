//用桶排序写写
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int bucket[101]={0};
    int* ans=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    int i;
    //往桶里装东西
    for(i=0;i<numsSize;i++)
    {
        bucket[nums[i]]++;
    }
    int sum=0,j=0;
    bucket[1]=bucket[0];
    for(i=2;i<numsSize-2;i++){
        bucket[i]=bucket[i-1]+bucket[i-2];
    }
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<nums[i];j++)
        {
            sum=sum+bucket[j];
        }
        ans[i]=sum;
        sum=0;
    }
    return ans;
}
