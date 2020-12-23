//https://leetcode-cn.com/problems/first-unique-character-in-a-string/submissions/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,0);
        int ans = -1, sizeOfs = s.size();
        for(int i = 0;i < sizeOfs; i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < sizeOfs; i++){
            if(arr[s[i] - 'a'] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};