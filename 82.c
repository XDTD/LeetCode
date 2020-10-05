void merge(int* nums1, int m, int* nums2, int n) {
    int i=m-1,j=n-1,idx=m+n-1;
        while(idx>=0){
            if(j<0||(i>=0&&nums1[i]>=nums2[j])){
                nums1[idx]=nums1[i];
                i--;
                idx--;
            }
            else{
                nums1[idx]=nums2[j];
                j--;
                idx--;
            }
        }
}
