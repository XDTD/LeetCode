#include<vector>
#include<iostream>
using namespace std;

    int longestMountain(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int state = 0, curLen = 1, pre = A[0], ans = 0;
        for(int i = 1; i < A.size(); i++){
            if(pre == A[i]){
                state = 0;
                curLen = 0;
            }
            if(state == 0){
                if(A[i] > pre){
                    state = 1;
                }else{
                    curLen = 0;
                }
            }else if(state == 1){
                if(A[i] < pre){
                    state = 2;
                }
            }else{
                if(A[i] > pre){
                    state = 1;
                    curLen = 1;
                }
            }
            pre = A[i];
            curLen++;
            if(state == 2) 
                ans = max(ans, curLen);
        }
        return ans >= 3 ? ans : 0;
    }

    int main(){
        vector<int> a ={875,884,239,731,723,685};
        cout << longestMountain(a) << endl;
    }