#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        int sum = 0, maxNum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        if(sum & 1 == 1)
            return false;
        int target = sum / 2;
        if(target < maxNum)
            return false;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= target; j++){
                if(nums[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-nums[i]] | dp[i-1][j];
            }
        }
        return dp[n-1][target];
    }

    int main(){
        vector<int> a = {9,5};
        cout << canPartition(a) << endl;
        return 0;
    }