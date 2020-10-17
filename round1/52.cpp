//important
class Solution {
public:
    int totalNQueens(int n) {
        solve(n, 0, 0, 0, 0);
        return ans;
    }

    void solve(int n, int row, int columns, int diagonal1, int diagonal2){
        if(row == n){
            ans++;
        }else{
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonal1 | diagonal2));
            while(availablePositions != 0){
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions-1);
                solve(n, row + 1, columns|position, (diagonal1|position) << 1, (diagonal2|position) >>1);
            }
        }
    }

private:
    int ans = 0;
};