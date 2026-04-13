# Last updated: 13/04/2026, 23:53:08
1class Solution:
2    def maxRepOpt1(self, s: str) -> int:
3        s+=" "
4        n=len(s)
5        mp={}
6        freq={}
7        idx=0
8        for i in range(0,n-1):
9            if s[i] not in mp:
10                mp[s[i]]=[]
11                freq[s[i]]=0
12            if s[i]!=s[i+1]:
13                mp[s[i]].append([idx,i])
14                idx=i+1
15            freq[s[i]]+=1
16        # print(mp)
17
18        ans=0
19        for key,val in mp.items():
20            m=len(val)
21            for i in range(m-1):
22                if(val[i][1]==val[i+1][0]-2):
23                    a1=val[i][1]-val[i][0]+1
24                    a2=val[i+1][1]-val[i+1][0]+1
25                    if(freq[key]-a1-a2>0):
26                        ans=max(ans,a1+a2+1)
27                    else:
28                        ans=max(ans,a1+a2)
29                else:
30                    a1=val[i][1]-val[i][0]+1
31                    if(freq[key]-a1>0):
32                        ans=max(ans,a1+1)
33                    else:
34                        ans=max(ans,a1)
35            a=val[m-1][1]-val[m-1][0]+1
36            if(freq[key]-a>0):
37                ans=max(ans,a+1)
38            else:
39                ans=max(ans,a)
40        return ans
41
42
43        