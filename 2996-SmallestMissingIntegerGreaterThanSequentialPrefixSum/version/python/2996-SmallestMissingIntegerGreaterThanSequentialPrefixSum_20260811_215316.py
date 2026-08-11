# Last updated: 11/8/2026, 9:53:16 pm
1from collections import Counter
2class Solution:
3    def missingInteger(self, nums: List[int]) -> int:
4        sum=nums[0]
5        for i in range(1,len(nums)):
6            if nums[i]!=nums[i-1]+1:
7                break
8            sum+=nums[i]
9        nums.sort()
10        for x in nums:
11            if x==sum:
12                sum+=1
13        return sum
14