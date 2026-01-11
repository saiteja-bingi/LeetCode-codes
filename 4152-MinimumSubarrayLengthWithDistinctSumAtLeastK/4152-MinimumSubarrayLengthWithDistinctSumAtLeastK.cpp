// Last updated: 1/11/2026, 11:09:55 AM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int len=INT_MAX;
        map<int,int>mp;
        while(j<n){
            if(mp[nums[j]]==0){
                sum+=nums[j];
            }
            mp[nums[j]]++;
            while(sum>=k&&i<=j){
                // if(mp[nums[i]]==0){
                //     sum+=nums[i];
                //     mp[nums[i]]++;
                // }
                len=min(len,j-i+1);
                if(mp[nums[i]]==1) sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            // cout<<i<<" "<<j<<endl;
            j++;
        }
        if(sum>=k) len=min(len,j-i+1);
        // cout<<i<<"* "<<j<<" "<<sum<<endl;
        if(len==INT_MAX) return -1;
        return len;
    }
};