// Last updated: 27/8/2026, 8:41:21 pm
1class Solution {
2public:
3    string lexGreaterPermutation(string s1, string t) {
4        int n=t.size();
5        for(int p=n-1;p>=0;p--){
6            vector<int>cnt(26,0);
7            for(auto it:s1){
8                cnt[it-'a']++;
9            }
10            bool ok=true;
11            for(int i=0;i<p;i++){
12                if(cnt[t[i]-'a']==0){
13                    ok=false;
14                    break;
15                }
16                cnt[t[i]-'a']--;
17            }
18            if(!ok) continue;
19            for(int c=t[p]-'a'+1;c<26;c++){
20                if(cnt[c]==0) continue;
21                string ans=t.substr(0,p);
22                ans+=char('a'+c);
23                cnt[c]--;
24                for(int x=0;x<26;x++){
25                    while(cnt[x]>0){
26                        ans+=char('a'+x);
27                        cnt[x]--;
28                    }
29                }
30                return ans;
31            }
32        }
33        return "";
34    }
35};