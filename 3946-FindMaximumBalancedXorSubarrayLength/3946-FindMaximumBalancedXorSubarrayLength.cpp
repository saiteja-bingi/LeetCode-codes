// Last updated: 12/1/2025, 7:13:30 PM
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        int eo=0;
        int ans=0,x=0;
        unordered_map<string,int>mp;
        mp["0_0"]=-1;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]%2==0) eo++;
            else eo--;
            string k=to_string(x)+"_"+to_string(eo);
            if(mp.count(k)){
                ans=max(ans,i-mp[k]);
            }
            else mp[k]=i;
        }
        return ans;
        
    }
};