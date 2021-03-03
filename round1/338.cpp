//https://leetcode-cn.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        int highBit = 0; //最高位比特代表的数，是2的n次方
        for(int i = 0; i < num + 1; i++){
            if(i > 1 && (i & (i - 1)) == 0){
                highBit = i;
            }
            else
                ans[i] = ans[i - highBit] + 1;
        }
        return ans;
    }
};