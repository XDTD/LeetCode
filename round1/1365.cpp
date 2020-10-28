//https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> bucket(101, 0);
        vector<int> ans(nums.size(), 0);
        for(const auto &x : nums){
            bucket[x]++;
        }
        for(int i = 1; i < bucket.size(); i++){
            bucket[i] += bucket[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            ans[i] = (nums[i] == 0) ? 0 : bucket[nums[i]-1];
        }
        return ans;
    }
};