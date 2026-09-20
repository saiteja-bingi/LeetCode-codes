// Last updated: 20/9/2026, 9:00:35 am
1class Solution {
2public:
3    long long maxValue(vector<int>& nums) {
4        long long ts=0;
5        int n=nums.size();
6        for(int i=0;i<n;i++){
7            if(i%2==0) ts+=nums[i];
8            else ts-=nums[i];
9        }
10        long long ans=ts;
11        long long pref=0;
12        long long ar[2]={0,LLONG_MAX};
13        for(int j=0;j<n;j++){
14            if(j&1) pref+=nums[j];
15            else pref-=nums[j];
16            if(ar[(j+1)%2]!=LLONG_MAX){
17                ans=max(ans,ts+2*(pref-ar[(j+1)%2]));
18            }
19            ar[(j+1)%2]=min(ar[(j+1)%2],pref);
20            // cout<<ev<<" "<<od<<" "<<ans<<endl;
21        }
22        return ans;
23    }
24};
25
26/*
27all(even)-all(odd)
28
29r(e)+s(o)-r(o)-s(e)
30t(r)-s(e)+s(o)-t(o)+s(o)-s(e)
31t(r)-t(o)+2*s(o)-2*s(e)
32ts+2*(o-e)
33*/