// Last updated: 09/02/2026, 21:07:06
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>dp;
        int maxsum=accumulate(arr.begin(),arr.end(),0);
        dp[arr[0]] = 1;
        dp[-arr[0]] +=1; 
        for(int i=1;i<n;i++){
            unordered_map<int,int>temp;
            for(auto it:dp){
                int sum=it.first;
                int ways=it.second;
                temp[sum+arr[i]]+=ways;
                temp[sum-arr[i]]+=ways;
            }
            dp=temp;
        }
        return dp[target];
    }
};