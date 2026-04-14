// Last updated: 15/04/2026, 00:46:28
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int c1=0,c2=0,ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) c1++;
            else c2++;
            if(mp.count(c1-c2)){
                ans=max(ans,i-mp[c1-c2]);
            }
            else{
                mp[c1-c2]=i;
            }
        }
        return ans;
    }
};