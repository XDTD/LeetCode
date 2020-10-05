#include<stdio.h>


int main(void){
    int n=2;
    printf("%d\n",n&(n-1));
    printf("%d",((n&(n-1))==0));





}


bool isPowerOfTwo(int n) {
    if(n<=0)
        return false;
    return ((n&(n-1))==0);
}
