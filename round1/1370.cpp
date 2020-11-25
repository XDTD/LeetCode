class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<int> bucket(26,0);
        for(auto c : s){
            bucket[c - 'a']++;
        }
        while(ans.size() < s.size()){
            for(int i = 0; i < 26; i++){
                if(bucket[i] > 0){
                    bucket[i]--;
                    ans.push_back(i + 'a');
                }
            }
            for(int i = 25; i >= 0; i--){
                if(bucket[i] > 0){
                    bucket[i]--;
                    ans.push_back(i + 'a');
                }
            }
        }
        return ans;
    }
};