// Last updated: 09/08/2026, 08:16:28
1class Solution {
2public:
3    long long weightedSum(vector<int>& parent, vector<int>& nums) {
4        int n=parent.size();
5        vector<vector<int>>c(n);
6        for(int i=1;i<n;i++){
7            c[parent[i]].push_back(i);
8        }
9        vector<int>s(n,0);
10        s[0]=1;
11        queue<int>q;
12        q.push(0);
13        int h=1;
14        while(!q.empty()){
15            int k=q.front();q.pop();
16            h=max(h,s[k]);
17            for(auto x:c[k]){
18                s[x]=s[k]+1;
19                q.push(x);
20            }
21        }
22        long long ans=0;
23        for(int i=0;i<n;i++){
24            ans+=(long long)nums[i]*(h-s[i]+1);
25        }
26        return ans;
27    }
28};