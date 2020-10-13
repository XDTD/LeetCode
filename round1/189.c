/*void rotateSingle(int* nums,int numsSize){
    int i=0,tmp=nums[numsSize-1];
    for(i=numsSize-1;i>0;i--){
        nums[i]=nums[i-1];
    }
    nums[0]=tmp;
}

void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    for(;k>0;k--)
        rotateSingle(nums,numsSize);
}*/

/**
* 两种思路，一种一次移一位，移动k次
*一种先反转前n-k位，再反转后k位，再反转整个数组
*/
void reverse(int* nums,int numsSize){
    int i=0;
    for(i=0;i<numsSize/2;i++){
        int tmp=nums[numsSize-i-1];
        nums[numsSize-i-1]=nums[i];
        nums[i]=tmp;
    }

}

void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    reverse(nums,numsSize-k);
    reverse(&nums[numsSize-k],k);
    reverse(nums,numsSize);
}
