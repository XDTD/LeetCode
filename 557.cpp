//反转字符串中的单词 III
//思路:一次遍历，找空格然后区间翻转字符串
//https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    int start = 0,end = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || i == s.size() - 1){
            end = i==s.size() - 1?i: i - 1;
            for(int j = start; j <= (start+end)/2; j++){
                swap(s[j],s[end-(j-start)]);
            }
            start = i + 1;
        }
    }
    return s;
}


int main(){
    string s = "Let's take LeetCode contest";
    s = reverseWords(s);
    cout << s << endl;
    return 0;
}
