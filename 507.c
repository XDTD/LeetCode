#include <stdio.h>

#define bool int
bool checkPerfectNumber(int num) {
    if(num==6)
        return true;
    int i=1,num1=num,num2=num;
    while(num1>0){
        num1-=i;
        i++;
    }
    i=1;
    while(num2>0){
        num2-=i*i*i;
        i=i+2;
    }
    int tmp=num-num/10*10;
    return (num1==0)&&(num2==0)&&(tmp==8||tmp==6);
}

int main(void){
    int num=1;
    if(num==6)
        return 1;
    int i=1,num1=num,num2=num;
    while(num1>0){
        num1-=i;
        i++;
    }
    i=1;
    while(num2>0){
        num2-=i*i*i;
        i=i+2;
    }
    printf("%d %d ",num1,num2);
    printf("%d ",num1==0&&num2==0);
    return 0;
}
