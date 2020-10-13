#include <malloc.h>
#include "string.h"
#include "stdio.h"
#include<stdio.h>

int* getNext(char* needle){
    int lenOfneedle=strlen(needle);
    int* next=(int *) malloc(sizeof(int)*lenOfneedle);
    next[0] = -1;
    int j = 0, k = -1;
    while(j<lenOfneedle - 1){
        if(k == -1 || needle[k] == needle[j]){
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}


char* getSameStr(char* haystack, char* needle){
    int lenOfhaystack=strlen(haystack),lenOfneedle=strlen(needle);
    if(lenOfneedle==0)
        return 0;
    int* next = getNext(needle);
    int i=0,j=0;
    while(i < lenOfhaystack && (j <lenOfneedle)){
        if(j == -1 || haystack[i] == needle[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    char * dest=(char * )malloc(sizeof(char)*(i-j));
    if(j == lenOfneedle)
        strncpy(dest, haystack+j-1, i-j);
    return dest;
}



int main(){
    char* s1="anbs";
    char* s2="nb";
    getSameStr(s1,s2);
}
