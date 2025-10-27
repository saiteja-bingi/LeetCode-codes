# Last updated: 10/27/2025, 7:10:42 PM
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_mp={}
        for i,num in enumerate(nums):
            diff=target-num
            if diff in num_mp:
                return [num_mp[diff],i]
            num_mp[num]=i