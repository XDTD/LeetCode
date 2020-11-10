//https://leetcode-cn.com/problems/valid-mountain-array/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int state = 0, pre = A[0];
        for(int i = 1; i < A.size(); i++){
            if(A[i] == pre)
                return false;
            else if(A[i] < pre ){
                if(state != 0){
                    state = 2;
                } 
                else 
                    return false;
            }else{
                if(state != 2){
                    state = 1;
                }else
                    return false;
            }
            pre = A[i];
        }
        return state == 2 ? true : false;
    }
};