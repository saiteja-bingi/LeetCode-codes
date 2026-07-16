# Last updated: 16/7/2026, 10:48:56 pm
1class Solution:
2    def gcdSum(self, nums: list[int]) -> int:
3        pg=[]
4        mx=nums[0]
5        for i in range(len(nums)):
6            mx=max(mx,nums[i])
7            pg.append(gcd(nums[i],mx))
8        pg.sort()
9        i,j=0,len(nums)-1
10        ans=0
11        while i<j:
12            ans+=gcd(pg[i],pg[j])
13            i+=1
14            j-=1
15        return ans
16