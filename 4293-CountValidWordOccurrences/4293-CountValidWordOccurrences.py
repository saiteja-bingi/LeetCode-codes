# Last updated: 19/8/2026, 11:58:57 pm
from collections import Counter
class Solution:
    def countWordOccurrences(self, chunks: list[str], queries: list[str]) -> list[int]:
        s=" "
        for t in chunks:
            s+=t
        print(s)
        s+=" "

        s=list(s)
        for i in range(1,len(s)-1):
            if(s[i]=='-'):
                if('a'<=s[i-1]<='z' and 'a'<=s[i+1]<='z'):
                    continue
                else:
                    s[i]=' '
        s="".join(s)

        # print(s)
        mp=Counter(s.split())
        return [mp[q] for q in queries]

