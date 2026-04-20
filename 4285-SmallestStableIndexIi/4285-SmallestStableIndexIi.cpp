// Last updated: 20/4/2026, 7:42:24 am
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=min(pre[i+1],nums[i]);
        }
        int ma=nums[0];
        for(int i=0;i<n;i++){
             ma=max(ma,nums[i]);
            if(ma-pre[i]<=k) return i;
        }
        return -1;
    }
};