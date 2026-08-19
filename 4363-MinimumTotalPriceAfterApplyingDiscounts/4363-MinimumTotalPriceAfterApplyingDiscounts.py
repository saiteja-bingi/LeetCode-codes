# Last updated: 19/8/2026, 11:57:42 pm
class Solution:
    def minPrice(self, prices: list[int], discounts: list[int]) -> float:
        prices.sort(reverse=True)
        discounts.sort(reverse=True)
        j=0
        ans=0.0
        for p in prices:
            if j<len(discounts):
                ans+=p*(100.0-discounts[j])/100
                j+=1
            else:
                ans+=p
        return ans
        