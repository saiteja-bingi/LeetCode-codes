# Last updated: 11/8/2026, 9:50:24 pm
1from collections import Counter
2class Solution:
3    def missingInteger(self, nums: List[int]) -> int:
4        sum=nums[0]
5        for i in range(1,len(nums)):
6            if nums[i]!=nums[i-1]+1:
7                break
8            sum+=nums[i]
9        mp=Counter(nums)
10        while mp[sum]:
11            sum+=1
12        return sum
13        
14