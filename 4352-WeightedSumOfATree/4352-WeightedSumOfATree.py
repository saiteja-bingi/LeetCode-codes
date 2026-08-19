# Last updated: 19/8/2026, 11:58:05 pm
from collections import deque
class Solution:
    def weightedSum(self, parent: list[int], nums: list[int]) -> int:
        n=len(parent)
        chl=[ [] for _ in range(n)]

        for i in range(1,n):
            chl[parent[i]].append(i)
        
        d=1;ans=sum=0
        q=deque()
        q.append((0,d))
        while q:
            p,l=q.popleft()
            d=l
            sum+=nums[p]
            ans+=(nums[p]-nums[p]*l)
            for c in chl[p]:
                q.append((c,l+1))

        ans+=d*sum
        return ans

