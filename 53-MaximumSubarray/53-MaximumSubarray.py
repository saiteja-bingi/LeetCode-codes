# Last updated: 10/27/2025, 7:10:19 PM
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum=currsum=nums[0]
        for i in range(1,len(nums)):
            currsum=max(nums[i],currsum+nums[i])
            maxsum=max(maxsum,currsum)

        return maxsum
