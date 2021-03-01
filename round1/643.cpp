//https://leetcode-cn.com/problems/maximum-average-subarray-i/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        ans = sum;  //只有k个数的情况，初始化
        for(int i = k; i < nums.size(); i++){
            double temp = sum - nums[i-k] + nums[i];
            ans = max(temp, ans);
            sum = temp;
        }
        return 1.0 * ans / k ;  //精度
    }
};