# Last updated: 10/8/2026, 11:24:24 pm
1class Solution:
2    def minPrice(self, prices: list[int], discounts: list[int]) -> float:
3        prices.sort(reverse=True)
4        discounts.sort(reverse=True)
5        j=0
6        ans=0.0
7        for p in prices:
8            if j<len(discounts):
9                ans+=p*(100.0-discounts[j])/100
10                j+=1
11            else:
12                ans+=p
13        return ans
14        