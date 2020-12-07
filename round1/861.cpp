//https://leetcode-cn.com/problems/score-after-flipping-matrix/submissions/
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ans = 0, K = A.size(), N = A[0].size();
        for(int j = 0; j < N; j++){
            int nNodes = 0;
            for(int i = 0; i < K; i++){
                nNodes = nNodes + (A[i][0] == 1 ? A[i][j] : 1 - A[i][j]);
            }
            nNodes = max(nNodes, K - nNodes);
            ans = ans + nNodes * (1 << (N - j - 1));
        }
        return ans;
    }
};