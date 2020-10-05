#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1;
            int right = i - 1;
            ans = max(ans, (right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;
}

int main(){
	int a[6] = {2,1,5,6,2,3};
	vector<int> heights(a,a+6);
	int ans=largestRectangleArea(heights);
	return 0;
}
