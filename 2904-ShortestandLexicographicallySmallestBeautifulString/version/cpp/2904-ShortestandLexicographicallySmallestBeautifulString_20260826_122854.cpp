// Last updated: 26/8/2026, 12:28:54 pm
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        int n=s.size(),i=0,c=0;
5        string ans;
6        for(int j=0;j<n;j++){
7            if(s[j]=='1') c++;
8            while(i<j&&c>k){
9                if(s[i]=='1') c--;
10                i++;
11            }
12            if(c==k){
13                while(i<=j&&s[i]=='0') i++;
14                string r=s.substr(i,j-i+1);
15                if(ans==""||r.size()<ans.size()||(r<ans&&r.size()==ans.size())) ans=r;
16            }
17        }
18        return ans;
19    }
20};