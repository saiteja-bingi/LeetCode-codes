# Last updated: 12/8/2026, 10:04:41 pm
1from collections import Counter
2class Solution:
3    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
4        n=len(nums)
5        i=0
6        ans=0
7        mp=Counter()
8        for j in range(0,n):
9            mp[nums[j]]+=1
10            while(i<j and mp[nums[j]]>k):
11                mp[nums[i]]-=1
12                i+=1
13            ans=max(ans,j-i+1)
14        return ans
15            