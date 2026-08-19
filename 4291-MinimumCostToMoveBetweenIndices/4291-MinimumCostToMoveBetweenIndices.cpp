// Last updated: 19/8/2026, 11:59:01 pm
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>close(n,0);
        close[0]=1;close[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            if(abs(nums[i]-nums[i-1])<=abs(nums[i]-nums[i+1])){
                close[i]=i-1;
            }
            else close[i]=i+1;
        }
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+((close[i]<i)?1:abs(nums[i]-nums[i-1]));
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+((close[i]>i)?1:abs(nums[i]-nums[i+1]));
        }
        vector<int>ans;
        for(auto q:queries){
            int l=q[0],r=q[1];
            if(l<r){
                ans.push_back(right[l]-right[r]);
            }
            else ans.push_back(left[l]-left[r]);
        }
        return ans;
    }
};