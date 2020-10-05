#include<stdio.h>

int peakIndexInMountainArray(int* A, int ASize) {
    int i=ASize/2;
    if(A[i]>A[i+1]&&A[i]>A[i-1])
        return i;
    else if(A[i]<A[i+1]){
        int tmp=i;
        return i+peakIndexInMountainArray(&A[tmp],ASize-tmp);
    }
    else{
        int tmp=i;
        return peakIndexInMountainArray(&A[0],ASize-tmp);
    }
    return 0;
}


int main(void){
    int A[10]={40,48,61,75,100,99,98,39,30,10};
    printf("%d",peakIndexInMountainArray(A,10));

}
