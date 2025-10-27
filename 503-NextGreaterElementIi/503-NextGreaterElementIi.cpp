// Last updated: 10/27/2025, 7:06:56 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i]);
            }
            while(!st.empty()&&nums[i]>=st.top()){
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};