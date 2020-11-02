//https://leetcode-cn.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> us{ nums1.begin(), nums1.end() };
        for (auto& iter : nums2) {
            if (us.find(iter) != us.end()) {
                us.erase(iter);
                ans.emplace_back(iter);
            }
        }
        return ans;
    }
};