#define min(a,b) a<b?a:b

int mySqrt(int x){
    int L=0;
    int R=x;
    while(L<R){
        int mid=(L+R)/2;
        if(mid*mid>x)  R=mid;
        else if(mid*mid<x) L=mid;
        else return mid;
    }
    return L;
}