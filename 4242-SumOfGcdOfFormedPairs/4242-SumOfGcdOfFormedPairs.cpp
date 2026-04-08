// Last updated: 08/04/2026, 23:54:46
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        vector<int>preg(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            preg[i]=__gcd(nums[i],mx);
        }
        sort(preg.begin(),preg.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
            ans+=__gcd(preg[i],preg[j]);
            i++;
            j--;
        }
        return ans;
    }
};