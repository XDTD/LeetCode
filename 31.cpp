#include<vector>
#include<algorithm>

using namespace std;

    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, j = 0;
        while(i >= 0){
            if(nums[i] > nums[i+1]){
                i--;
            }else{
                j = i + 1;
                break;
            }
        }
        while(j < nums.size() && i >= 0){
            if( j + 1 < nums.size() && nums[j+1] > nums[i] ){
                j++;
            }else{
                swap(nums[i], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }


int main(){
    vector<int> a = {1,2};
    nextPermutation(a);
}