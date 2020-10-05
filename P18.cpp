//https://leetcode-cn.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int ii = j+1, jj = n-1;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) continue;
                if(nums[i] + nums[j] + nums[n-1] + nums[n-1] < target) continue;
                while(ii < jj){
                    int tmp = nums[i] + nums[j] + nums[ii] + nums[jj] ; 
                    if(tmp == target) ans.push_back({nums[i], nums[j], nums[ii], nums[jj] });
                    if(tmp < target) {
                        do{
                            ii++;
                        }while(ii < jj && nums[ii] == nums[ii-1]);
                    }
                    else{
                        do{
                           jj--;
                        }while(ii < jj && nums[jj] == nums[jj+1]);
                    }
                } 
            }
        }
        return ans;
    }
};