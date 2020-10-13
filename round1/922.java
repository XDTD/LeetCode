//%70

class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int j=1;
        for(int i=0;i<A.length;i=i+2){
            if(i%2==A[i]%2){
                continue;
            }
            else{
                while(A[j]%2!=i%2){
                    j=j+2;
                }
                int tmp=A[j];
                A[j]=A[i];
                A[i]=tmp;
            }
        }
        return A;
    }
}