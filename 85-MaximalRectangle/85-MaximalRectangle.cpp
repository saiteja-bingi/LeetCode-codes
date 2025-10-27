// Last updated: 10/27/2025, 7:09:32 PM
class Solution {
public:
    vector<int> findSmall(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRec(vector<int>&heights){
        int n=heights.size();
        vector<int>nextSmall=findSmall(heights);
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            int prevsmall;
            while(!st.empty()&&heights[i]<=heights[st.top()]){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
        vector<vector<int>> presum(row, vector<int>(col, 0));
        for(int i=0;i<col;i++){
            if(matrix[0][i]=='1'){
                presum[0][i]=1;
            }
            else{
                presum[0][i]=0;
            }
            for(int j=1;j<row;j++){
                if(matrix[j][i]=='1'){
                    presum[j][i]=1+presum[j-1][i];
                }
                else{
                    presum[j][i]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            int area=largestRec(presum[i]);
            ans=max(ans,area);
        }
        return ans;
    }
};