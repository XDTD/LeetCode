#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

double findMedianSortedArrays(int* A, int nums1Size, int* B, int nums2Size){
    //二分法划分的上下边界
    int L=0,R=nums1Size;
    int i,j;
    double ans=0;
    while(L<R){
        i=(L+R)/2;
        j=(nums1Size+nums2Size+1)/2-i;
        if(A[i-1]>B[j])
            L=i;
        else if(B[j-1]>A[i])
            R=i;
        else
            break;    
    }
    if((nums1Size+nums2Size)%2==1)
        ans=max(A[i-1],B[j-1]);
    else
        ans=(max(A[i-1],B[j-1])+min(A[i],B[j]))/2;
    return ans;
}