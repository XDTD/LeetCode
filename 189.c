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
* ����˼·��һ��һ����һλ���ƶ�k��
*һ���ȷ�תǰn-kλ���ٷ�ת��kλ���ٷ�ת��������
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
