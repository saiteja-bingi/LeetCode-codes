// Last updated: 1/8/2026, 8:50:14 pm
1
2class Solution {
3public:
4    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
5        int n=monsters.size();
6        vector<long long>bns(n,0);
7        for(auto &it:boosts){
8            bns[it[0]]+=it[2];
9            if(it[1]+1<n) bns[it[1]+1]-=it[2];
10        }
11        for(int i=1;i<n;i++){
12            bns[i]+=bns[i-1];
13        }
14        // for(auto it:bns){
15        //     cout<<it<<" ";
16        // }
17        long long ans=0;
18        int i=n-1;
19        while(i>=0&&bns[i]>=monsters[i]){
20            i--;
21        }
22        if(i>=0){
23            ans+=monsters[i]-bns[i];
24            i--;
25        }
26        while(i>=0){
27            ans+=monsters[i];
28            i--;
29        }
30        return ans;
31    }
32};