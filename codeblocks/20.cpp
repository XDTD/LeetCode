#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

bool isValid(string s) {
    vector<char> sk;
    for (int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='['||ch=='{'||ch=='(')
            sk.push_back(ch);
        else if(ch==']'){
            if(sk[sk.size()-1]!='[')
                return false;
            else
                sk.pop_back();
        }
        else if(ch==')'){
            if(sk[sk.size()-1]!='(')
                return false;
            else
                sk.pop_back();
        }
        else if(ch=='}'){
            if(sk[sk.size()-1]!='{')
                return false;
            else
                sk.pop_back();
        }
    }
    if(s.empty())
        return true;
    return false;
}


int main(){
    string s="()";
    cout << "Value of str is : " << isValid(s) << endl;
}
