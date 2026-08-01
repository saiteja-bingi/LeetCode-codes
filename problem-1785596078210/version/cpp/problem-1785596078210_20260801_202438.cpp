// Last updated: 1/8/2026, 8:24:38 pm
1class Solution {
2public:
3    int maximumWidth(vector<int>& planks) {
4        map<int,int>mp;
5        for(auto it:planks) mp[it]++;
6        map<int,int>mp2;
7        vector<int>vec;
8        for(auto&[x,y]:mp) vec.push_back(x);
9        for(int i=0;i<vec.size();i++){
10            mp2[vec[i]]+=mp[vec[i]];
11            for(int j=0;j<=i;j++){
12                if(i!=j) mp2[vec[i]+vec[j]]+=min(mp[vec[i]],mp[vec[j]]);
13                else mp2[2*vec[i]]+=mp[vec[i]]/2;
14            }
15        }
16        int ans=0;
17        for(auto&[x,y]:mp2) ans=max(ans,y);
18        return ans;
19    }
20};