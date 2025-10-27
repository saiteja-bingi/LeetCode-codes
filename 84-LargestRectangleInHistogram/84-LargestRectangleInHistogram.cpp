// Last updated: 10/27/2025, 7:09:34 PM
class Solution {
public:
    vector<int> findnext(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {;
        vector<int>nextSmall=findnext(heights);
        stack<int>st;
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int prevsmall;
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                prevsmall=st.top();
            }
            else{
                prevsmall=-1;
            }
            st.push(i);
            int area=heights[i]*(nextSmall[i]-prevsmall-1);
            ans=max(ans,area);
        }
        return ans;
    }
};