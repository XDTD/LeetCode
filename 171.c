#include<stdio.h>

int Mypow(x,y){
    if(y==0)
        return 1;
    int i,res=1;
    for(i=0;i<y;i++){
        res*=x;
    }
    return res;
}


int titleToNumber(char* s) {
    int i=0,res=0,last;
    while(s[i]!='\0'){
        i++;
    }
    i--;
    last=i;
    while(i>=0){
        res+=((int)s[i]-64)*pow(26,last-i);
        i--;
    }
    return res;
}


