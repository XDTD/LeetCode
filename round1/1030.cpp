//https://leetcode-cn.com/problems/matrix-cells-in-distance-order/submissions/
class Solution {
public:
    const int dr[4] = {1, 1, -1, -1};
    const int dc[4] = {1, -1, -1, 1};

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        int maxDist = max(r0, R - r0 - 1) + max(c0, C - c0 - 1);
        int row = r0, col = c0;
        ans.push_back({row, col});
        for(int dist = 1; dist <= maxDist; dist++){
            row--;
            for(int i = 0; i < 4; i++){
                while((i % 2 == 0 && row != r0)|| (i % 2 != 0 && col != c0)){
                    if(row >= 0 && row < R && col >= 0 && col < C){
                        ans.push_back({row, col});
                    }
                    row += dr[i];
                    col += dc[i];
                }
            }
        } 
        return ans;
    }
};