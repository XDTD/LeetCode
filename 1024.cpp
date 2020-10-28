class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int start = 0, maxEnd = 0, n = clips.size();
        int ans = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(clips[i][0] <= start && clips[i][1] >= maxEnd){
                    maxEnd = clips[i][1];
                }
            }
            if(start == maxEnd){
                ans = -1;
                break;
            }
            start = maxEnd;
            ans++;
            if(maxEnd >= T)
                break;
        }
        return maxEnd >= T ? ans : -1 ;
    }
};