// Last updated: 10/27/2025, 7:06:50 PM
#include<bits/stdc++.h>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0,i=0,count=0;
        mp[0]=1;
        int n=nums.size();
        for(i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};