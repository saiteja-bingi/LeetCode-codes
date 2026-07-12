// Last updated: 12/7/2026, 10:08:36 pm
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int>temp=arr;
5        int n=arr.size();
6        sort(temp.begin(),temp.end());
7        map<int,int>mp;
8        int r=1;
9        for(int i=0;i<n;i++){
10            if(!mp.count(temp[i])) {mp[temp[i]]=r;r++;}
11        }
12        vector<int>ans(n);
13        for(int i=0;i<n;i++){
14            ans[i]=mp[arr[i]];
15        }
16        return ans;
17    }
18};