// Last updated: 12/7/2025, 11:21:51 AM
1class Solution {
2public:
3    long long maxPoints(vector<int>& v1, vector<int>& v2, int k) {
4        int n=v1.size();
5        vector<pair<int,int>>diff(n);
6        long long ans=0;
7        for(int i=0;i<n;i++){
8            diff[i]={v1[i]-v2[i],i};
9        }
10        sort(diff.begin(),diff.end());
11        int c=0;
12        for(int i=n-1;i>=0;i--){
13            if(c<k) ans+=v1[diff[i].second];
14            else{
15                ans+=max(v1[diff[i].second],v2[diff[i].second]);
16            }
17            c++;
18        }
19        return ans;
20    }
21};