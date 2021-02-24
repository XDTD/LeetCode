//https://leetcode-cn.com/problems/flipping-an-image/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A[0].size(), end = (n + 1)/ 2;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < end ; j++){
                int temp = A[i][j];
                A[i][j] = 1 - A[i][n-j-1];
                A[i][n-j-1] = 1 - temp;
            }
        }
        return A;
    }
};