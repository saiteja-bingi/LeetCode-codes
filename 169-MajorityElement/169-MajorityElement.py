# Last updated: 10/27/2025, 7:08:58 PM
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq=1
        ans=nums[0]
        for i in range(1,len(nums)):
            if ans==nums[i]:
                freq+=1
            else:
                freq-=1
            
            if freq==0:
                ans=nums[i]
                freq=1
        return ans

