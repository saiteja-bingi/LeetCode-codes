// Last updated: 15/8/2026, 6:49:56 am
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>cnt(32,0);
6        bool k=0;
7        for(int i=0;i<n;i++){
8            for(int j=0;j<32;j++){
9                if((nums[i])&(1<<j)) cnt[j]++;
10            }
11            if(nums[i]!=0) k=1;
12        }
13        if(!k) return 0;
14
15        bool f=0;
16        for(int i=0;i<32;i++) if(cnt[i]&1){f=1;break;}
17        if(f) return n;
18        return n-1;
19    }
20};
21