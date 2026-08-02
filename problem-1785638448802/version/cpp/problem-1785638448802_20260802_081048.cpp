// Last updated: 2/8/2026, 8:10:48 am
1class Solution {
2public:
3    int countRatioSubarrays(vector<int>& nums, int a, int b) {
4        int n=nums.size();
5        int ans=0;
6        for(int i=0;i<n;i++){
7            int x=0,y=0;
8            for(int j=i;j<n;j++){
9                if(nums[j]%2==0) x++;
10                else y++;
11                if(y>0&&(1ll*x*b<=1ll*a*y)) ans++;
12            }
13        }
14        return ans;
15    }
16};