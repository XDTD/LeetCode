class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>  minFreq(26, INT_MAX);
        vector<int>  freq(26, INT_MAX);
        vector<string> ans;
        for(string str : A){
            fill(freq.begin(), freq.end(), 0);
            for(char c : str){
                freq[c-'a']++;
            }
            for(int i = 0; i < 26; i++){
                minFreq[i] = min(freq[i], minFreq[i]);
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < minFreq[i]; j++){
                ans.emplace_back(1, i + 'a');  //C++ 11
            }
        }
        return ans;
    }
};