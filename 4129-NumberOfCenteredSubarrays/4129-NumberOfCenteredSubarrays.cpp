// Last updated: 1/11/2026, 11:10:02 AM
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        for(long long i=0;i<n;i++){
            map<long long,long long>mp;
            long long sum=0;
            for(long long j=i;j<n;j++){
                mp[nums[j]]++;
                sum+=nums[j];
                if(mp[sum]>0) ans++;
            }
        }
        return ans;
    }
};