# Last updated: 10/27/2025, 7:06:13 PM
class Solution:
    def check(self, nums: List[int]) -> bool:
        count=0
        for i in range(1,len(nums)):
            if(nums[i-1]>nums[i]):
                count+=1
        if nums[len(nums)-1]>nums[0]:
            count+=1
        if count<=1:
            return True
        return False