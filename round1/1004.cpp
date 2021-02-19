//https://leetcode-cn.com/problems/max-consecutive-ones-iii/submissions/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, n = A.size();
        int numOfzero = 0;
        while(r < n){
            if(A[r] == 0){
                numOfzero++;
            }
            r++;
            if(numOfzero > K ){
                if(A[l] == 0){
                    numOfzero--;
                }
                l++;
            }
        }
        return r - l;  //没有加1，因为
    }
};