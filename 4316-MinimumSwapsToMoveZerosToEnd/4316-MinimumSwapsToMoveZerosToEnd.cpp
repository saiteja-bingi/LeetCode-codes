// Last updated: 19/8/2026, 11:58:29 pm
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int ans=0,c=0;
        for(int i=0;i<n;i++) c+=(nums[i]==0);
        for(int i=0;i<n-c;i++){
            if(nums[i]==0) ans++;
        }
        return ans;
    }
};