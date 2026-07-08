// Last updated: 8/7/2026, 3:28:36 pm
1class Solution {
2public:
3    bool canMakeSubsequence(string s, string t) {
4        int n=s.size(),m=t.size();
5        if(n>m) return  false;
6        if(n==1) return true;
7        int i=0,j=0;
8        vector<int>a1(n,-1),a2(n,-1);
9        while(i<n&&j<m){
10            while(j<m&&s[i]!=t[j]) j++;
11            if(j<m) a1[i]=j;
12            i++;
13            j++;
14        }
15        i=n-1;j=m-1;
16        while(i>=0&&j>=0){
17            while(j>=0&&s[i]!=t[j]) j--;
18            if(j>=0) a2[i]=j;
19            i--;
20            j--;
21        }
22        if(a2[1]!=-1&&a2[1]!=0||a1[n-2]!=-1&&a1[n-2]!=m-1) return true;
23        for(int i=1;i<n-1;i++){
24            if(a1[i-1]!=-1&&a2[i+1]!=-1&&a2[i+1]-a1[i-1]-1>=1) return true;
25        }
26        return false;
27    }
28};
29
30/*
31    chnage one to bbecome sub sequence
32    
33*/