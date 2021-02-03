//https://leetcode-cn.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> nums(26,0);
        int n = s.size(), maxN = 0;
        while(right < n){
            nums[s[right] - 'A']++;
            maxN = max(maxN, nums[s[right] - 'A']);
            if(right - left + 1 - maxN > k){
                nums[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
