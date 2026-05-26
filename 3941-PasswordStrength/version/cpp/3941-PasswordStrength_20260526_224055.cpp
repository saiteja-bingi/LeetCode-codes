// Last updated: 26/5/2026, 10:40:55 pm
1class Solution {
2public:
3    int passwordStrength(string p) {
4        unordered_map<char,int>mp;
5        int ans=0;
6        for(int i=0;i<p.size();i++){
7            char ch=p[i];
8            if(!mp[ch]){
9                if('a'<=ch&&ch<='z') ans+=1;
10                else if('A'<=ch&&ch<='Z') ans+=2;
11                else if('0'<=ch&&ch<='9') ans+=3;
12                else ans+=5;
13            }
14            mp[ch]++;
15        }
16        return ans;
17    }
18};