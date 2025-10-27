// Last updated: 10/27/2025, 7:04:34 PM
#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        int n=arr.size();
        unordered_map<ll,unordered_map<ll,ll>>mp;
        ll pre=0;
        ll count=0;
        for(int i=0;i<n;i++){
            if(mp[arr[i]][pre-arr[i]]){
                count+=mp[arr[i]][pre-arr[i]];
            }
            pre+=arr[i];
            mp[arr[i]][pre]++;
            if(i>0&&arr[i]==0&&arr[i-1]==0) count--;
        }
        return count;
    }
};