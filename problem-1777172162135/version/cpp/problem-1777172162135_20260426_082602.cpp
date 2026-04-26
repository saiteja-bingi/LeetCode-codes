// Last updated: 26/4/2026, 8:26:02 am
1class Solution {
2public:
3    string sortVowels(string s) {
4        int n=s.size();
5        vector<int>vec(26,0);
6        unordered_map<char,int>tp;
7        int k=0;
8        for(auto it:s){
9            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
10                if(vec[it-'a']==0) tp[it]=k;
11                k++;
12                vec[it-'a']++;
13            }
14        }
15        string t="";
16        map<int,set<pair<int,char>>>mp;
17        for(int i=0;i<26;i++) mp[vec[i]].insert({tp[i+'a'],i+'a'});
18        for(auto[x,y]:mp){
19            string l="";
20            for(auto r:y){
21                char m=r.second;
22                for(int i=0;i<x;i++) l+=m;
23            }
24            t=l+t;
25        }
26        int i=0,m=t.size();
27        for(int k=0;k<n;k++){
28            char it=s[k];
29            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
30                s[k]=t[i]; i++;
31            }
32        }
33        return s;
34    }
35};