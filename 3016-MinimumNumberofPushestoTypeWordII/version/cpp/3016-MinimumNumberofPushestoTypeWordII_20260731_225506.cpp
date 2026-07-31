// Last updated: 31/7/2026, 10:55:06 pm
1class Solution {
2public:
3    int minimumPushes(string word) {
4        map<char,int>mp;
5        for(auto it:word) mp[it]++;
6        int c=0,ans=0,k=1;
7        vector<int>vec;
8        for(auto &[x,y]:mp) vec.push_back(y);
9        sort(vec.begin(),vec.end(),greater<int>());
10        for(auto y:vec){
11            if(c==8){
12                c=0;k++;
13            }
14            c++;
15            ans+=k*y;
16        }
17        return ans;
18    }
19};