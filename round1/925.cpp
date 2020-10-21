//https://leetcode-cn.com/problems/long-pressed-name/submissions/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(i < name.size()){
            int cnt1 = 1, cnt2 = 1;
            while(i < name.size() - 1 && name[i] == name[i+1]){
                i++;
                cnt1++;
            }
            while(j < typed.size() - 1 && typed[j] == typed[j+1]){
                j++;
                cnt2++;
            }
            if(name[i] != typed[j] || cnt2 < cnt1)
                return false;
            i++;
            j++; 
        }
        if(j != typed.size())
            return false; 
        return true;
    }
};