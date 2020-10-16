class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int i = 0, j = n - 1, pos = n - 1;
        while(i <= j){
            if(A[i] * A[i] < A[j] * A[j]){
                ans[pos--] = A[j]*A[j];
                j--;
            }else{
                ans[pos--] = A[i]*A[i];
                i++;
            }
        }
        return ans;
    }
};