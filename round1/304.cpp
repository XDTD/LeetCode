//https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            preSum.resize(m + 1, vector<int>(n + 1));  //为了不对（0，0）的情况做特殊处理所以+1
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j]; 
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1]; 
        //这里是row2+1和col2++1，注意
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */