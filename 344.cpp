//344. 反转字符串
//https://leetcode-cn.com/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++){
            swap(s[i], s[s.size()-1-i]);
        }
    }
};