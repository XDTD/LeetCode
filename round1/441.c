#include<stdio.h>

/**
*   ËÙ¶ÈÒ»°ã
*/

int arrangeCoins(int n) {
    int cnt=0;
    while(n>0){
         cnt++;
         n=n-cnt;
    }
    if(n<0)
        return (cnt-1);
    return cnt;
}

int main(void){
    int cnt=0;
    int n=5;
    while(n>0){
         cnt++;
         n=n-cnt;
         printf("cnt:%d  n:%d\n",cnt,n);
    }
    if(n<0)
        printf("%d",cnt-1);

    return 0;


}
