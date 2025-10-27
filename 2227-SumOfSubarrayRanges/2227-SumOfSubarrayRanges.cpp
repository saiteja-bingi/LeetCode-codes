// Last updated: 10/27/2025, 7:06:06 PM
class Solution {
public:
    vector<int> findnextmin(vector<int>&nums){
        int n=nums.size();
        if (n == 0) return {};
        stack<int>s;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]<=nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findprevmin(vector<int>&nums){
        int n=nums.size();
        if (n == 0) return {};
        stack<int>s;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]<nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findnextmax(vector<int>&nums){
        int n=nums.size();
        if (n == 0) return {};
        stack<int>s;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>=nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findprevmax(vector<int>&nums){
        int n=nums.size();
        if (n == 0) return {};
        stack<int>s;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextmin=findnextmin(nums);
        vector<int>prevmin=findprevmin(nums);
        vector<int>nextmax=findnextmax(nums);
        vector<int>prevmax=findprevmax(nums);
        long long sum_mins=0;
        long long sum_maxs=0;
        for(int i=0;i<n;i++){
            long long right=nextmin[i]-i;
            long long left=i-prevmin[i];
            sum_mins+=1LL*(right*left*nums[i]);
        }
        for(int i=0;i<n;i++){
            long long right=nextmax[i]-i;
            long long left=i-prevmax[i];
            sum_maxs+=1LL*(right*left*nums[i]);
        }
        return sum_maxs-sum_mins;
    }
};