#include<limits.h>
#include<stdio.h>
int main(){
    int a=INT_MAX;
    long long b=(long)a;
    long long c=b+1;
   printf("%d\n",LONG_MIN);
   printf("%d\n",b<c);
}
