#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool validPalindrome(char * s){
    int len=(int)strlen(s);
    int start=0,end=len-1,flag=0;
    while(start<end){
        if(s[start]!=s[end]){
            if(flag==0&&s[start+1]==s[end]){
                start++;
                flag=1;
            }
            else if(flag==0&&s[start]==s[end-1]){
                end--;
                flag=1;
            }
            else
                return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    char* s="aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    printf("%d",validPalindrome(s));
    return 0;
}