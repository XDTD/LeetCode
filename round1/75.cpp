//2020.10.07
//75. 颜色分类
//https://leetcode-cn.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0,p1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[i], nums[p1++]);
            }else if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                if(p0 < p1){
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};