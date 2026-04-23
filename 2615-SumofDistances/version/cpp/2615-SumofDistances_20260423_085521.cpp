// Last updated: 23/4/2026, 8:55:21 am
1class Solution {
2public:
3    vector<long long> distance(vector<int>& nums) {
4        long long n=nums.size();
5        vector<long long>ans(n,0);
6        unordered_map<long long,vector<long long>>mp;
7        for(long long i=0;i<n;i++){
8            mp[nums[i]].push_back(i);
9        }
10        for(auto &[x,vec]:mp){
11            if(vec.size()==1) ans[vec[0]]=0;
12            else{
13                long long m=vec.size();
14                vector<long long>dt(m),suf(m,0);
15                dt[0]=0;
16                for(long long i=1;i<m;i++){
17                    dt[i]=abs(vec[i]-vec[i-1]);
18                }
19                for(long long i=m-2;i>=0;i--) suf[i]=suf[i+1]+dt[i+1]+(m-2-i)*abs(vec[i]-vec[i+1]);
20                long long psum=0;
21                for(long long i=0;i<m;i++){
22                    psum+=dt[i];
23                    if(i-1>=0) psum+=(i-1)*abs(vec[i]-vec[i-1]);
24                    ans[vec[i]]=psum+suf[i];
25                }
26            }
27        }
28        return ans;
29    }
30};