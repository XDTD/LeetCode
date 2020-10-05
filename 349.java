class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> x = new HashSet();
        Set<Integer> y = new HashSet();
        for(int i=0;i<nums1.length;i++){
            if(!x.contains(nums1[i])){
                x.add(nums1[i]);
            }
        }
        for(int i=0;i<nums2.length;i++){
            if(x.contains(nums2[i])){
                y.add(nums2[i]);
            }
        }
        
        int[] res=new int[y.size()];
        int i=0;
        if(y.size()>=0){
            for(Integer num:y){
                res[i]=num.intValue();;
                i++;
            }
        }
        return res;
    }
}