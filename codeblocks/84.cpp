#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


string multiply(string num1, string num2) {
    int tmp[num1.length()+num2.length()]={0};
    int flag=0;
    string ans="";
    for(int i=0;i<num1.length();i++){
        for(int j=0;j<num2.length();j++){
            tmp[j+i]=(num1[num1.length()-1-i]-'0')*(num2[num2.length()-1-i]-'0')+tmp[i+j];
        }
    }
    for(int i=0;i<num1.length()+num2.length()  ;i++){
        tmp[i]=tmp[i]+flag;
        flag=tmp[i]/10;
        tmp[i]=tmp[i]%10;
        ans+=(tmp[i]+'0');
    }
    reverse(ans.begin(),ans.end());
    int i=0;
    while(ans[i]=='0') i++;
    ans=ans.substr(i);
    return ans;
}



int main(){
    string num1="2";
    string num2="3";
    cout << "Value of ans is : " << multiply(num1,num2) << endl;
}
