// Last updated: 09/02/2026, 21:05:11
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        vector<bool>arr(n,false);
        arr[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) arr[i]=true;
            else break;
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!arr[i]) c++;
            else break;
        }
        return c;
    }
};