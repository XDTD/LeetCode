//https://leetcode-cn.com/problems/reorganize-string/
//https://leetcode-cn.com/problems/reorganize-string/solution/767-zhong-gou-zi-fu-chuan-po-shi-wu-hua-de-fang-fa/
class Solution {
private:
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 按照频率从大到小排序
    }
public:
    string reorganizeString(string S) {
        unordered_map<char, int> umap;
        int maxFreq = 0;
        for (char s : S) {
…        for (int i = 0; i < vec.size(); i++) {
            while (vec[i].second--) {
                result[index] = vec[i].first;
                index += 2;
                if (index >= S.size()) index = 1; // 奇数位插满了插偶数位
            }
        }
        return result;
    }
};