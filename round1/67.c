#include<stdio.h>
#define max(a,b) a>b?a:b


char* addBinary(char* a, char* b) {
    int len_a=0,len_b=0,Flag=0;
    int i=0,j=0;
    while(a[i]!='\0')
        i++;
    len_a=i;
    while(b[j]!='\0')
        j++;
    len_b=j;
    int lenMax=max(len_a,len_b);
    printf("lenMax:%d",lenMax);printf("len a:%d",len_a);printf("len b:%d",len_b);
    char s[lenMax],tmp[lenMax+1];
    for(i=lenMax-1;i>=0;i--){
        int na=i<len_a?(int)(a[i]-'0'):0;
        int nb=i<len_b?(int)(b[i]-'0'):0;
        if(na+nb+Flag==3){
            s[i]='1';
            Flag=1;
            tmp[i+1]=s[i];
        }else if(na+nb+Flag==2){
            s[i]='0';
            Flag = 1;
            tmp[i+1]=s[i];
        }else{
            s[i]=(char)(na+nb+Flag+'0');
            Flag = 0;
            tmp[i+1]=s[i];
        }
        printf("\n%c",s[i]);

    }
    if(Flag==1){
        tmp[0]='1';
        return tmp;
    }
    return s;
}

int main(void){
    char *a="11",*b="1";
    char *c=addBinary(a,b);
    return 0;

}

/*
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
 /*
var addBinary = function(a, b) {
    var l = Math.max(a.length,b.length);
    var j = 0;
    var s = "";
    for(var i=0;i<l||j;i++){
        var na = a.length-1-i>=0?parseInt(a[a.length-1-i]):0;
        var nb = b.length-1-i>=0?parseInt(b[b.length-1-i]):0;
        if(na+nb==2){
            s=j+s;
            j = 1;
        }else if(na+nb+j==2){
            s=0+s;
            j = 1;
        }else{
            s = na+nb+j+s;
            j = 0;
        }
    }
    return s;
};*/
