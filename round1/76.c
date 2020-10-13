#include "stdio.h"
#include "malloc.h"
#include "string.h"
char * minWindow(char * s, char * t){
    int cntOft[128]={0},cntOfWindow[128]={0};
    int L=0,R=0;
    int lenOfs=(int)strlen(s),lenOft=(int)strlen(t);
    int LOfAns=0,ROfAns=lenOft-1;
    int i,cnt=0;
    for(i=0;i<lenOft;i++){
        cntOft[(int)t[i]]++;
    }
    while(R<lenOfs){
        int idx=(int)s[R];
        cntOfWindow[idx]++;
        if(cntOft[idx]>0&&cntOfWindow[idx]>=cntOft[idx]) cnt++;
        while(cnt==lenOfs){
            if(R-L+1<ROfAns-LOfAns+1){
                ROfAns=R;
                LOfAns=L;
            }
            idx=(int)s[L];
            cntOfWindow[idx]--;
            if(cntOft[idx]>0&&cntOfWindow[idx]<cntOft[idx]) cnt--;
            L++;
        }
        R++;
    }
    char *ans = malloc(sizeof(char) * (ROfAns-LOfAns+1));
    strncpy(ans, s+LOfAns, ROfAns-LOfAns+1);
    return ans;
}

int main(){
    char* s="ADOBECODEBANC";
    char * t="ABC";
    char* ans=minWindow(s,t);
    return  0;
}