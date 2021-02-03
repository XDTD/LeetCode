#include<vector>
#include<set>
#include<iostream>

using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    multiset<double> st;
    for(int i = 0; i < nums.size(); i++){
        if(st.size() >= k) st.erase(st.find(nums[i-k]));
        st.insert(nums[i]);
        if(i >= k - 1){
            auto mid = st.begin();
            std::advance(mid, k / 2 );
            ans.push_back((*mid + *prev(mid, (1-k%2)))/2); 
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,4,2,3};
    int k = 4;
    vector<double> temp = medianSlidingWindow(nums, k);
    cout <<temp[0] << endl;
    return 0;
}