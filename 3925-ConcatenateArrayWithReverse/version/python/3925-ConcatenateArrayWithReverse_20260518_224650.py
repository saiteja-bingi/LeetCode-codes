# Last updated: 18/5/2026, 10:46:50 pm
1from collections import Counter
2class Solution:
3    def countWordOccurrences(self, chunks: list[str], queries: list[str]) -> list[int]:
4        s=" "
5        for t in chunks:
6            s+=t
7        print(s)
8        s+=" "
9
10        s=list(s)
11        for i in range(1,len(s)-1):
12            if(s[i]=='-'):
13                if('a'<=s[i-1]<='z' and 'a'<=s[i+1]<='z'):
14                    continue
15                else:
16                    s[i]=' '
17        s="".join(s)
18
19        # print(s)
20        mp=Counter(s.split())
21        return [mp[q] for q in queries]
22
23