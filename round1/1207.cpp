//自己写的8ms
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        unordered_map<int, int> cmp;
        bool ans = true;
        for(int i = 0; i < arr.size(); i++){
            if(umap.find(arr[i]) == umap.end()){
                umap[arr[i]] = 1;
            }else{
                umap[arr[i]]++;
            }
        }
        for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
            if(cmp.find(iter->second) == cmp.end()){
                cmp[iter->second] = iter->first;
            }else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};


//官方题接，4ms,92.42%
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (const auto& x: arr) {
            occur[x]++;
        }
        unordered_set<int> times;
        for (const auto& x: occur) {
            times.insert(x.second);
        }
        return times.size() == occur.size();
    }
};