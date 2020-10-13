class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> x = new HashMap<>();
        HashMap<Integer, Integer> y = new HashMap<>();
        //List<Integer> z=new ArrayList<>();
        for(Integer num:nums1){
            if(x.containsKey(num))
                x.replace(num,x.get(num)+1);
            else
                x.put(num,1);
        }
        int i=0;
        for(Integer num:nums2){
            if(x.containsKey(num)&&x.get(num)>0){
                y.put(i,num);
                i++;
                x.replace(num,x.get(num)-1);
            }
        }
        /*for(Integer num:nums2){
            if(x.containsKey(num)&&x.get(num)>0){
                z.add(i,num);
                i++;
                x.replace(num,x.get(num)-1);
            }
        }*/
        int[] res=new int[y.size()];        
        for(Integer key:y.keySet()){
            res[key]=y.get(key).intValue();
        }
        /*for( i=0;i<z.size();i++){
            res[i]=z.get(i).intValue();
        }*/
        return res;
    }
}