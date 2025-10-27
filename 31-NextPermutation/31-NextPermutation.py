# Last updated: 10/27/2025, 7:10:11 PM
class Solution(object):
    def seclar(self,nums,index):
        n=len(nums)-1
        j=n
        while j>=0:
            if(nums[j]>nums[index]):
                nums[j],nums[index]=nums[index],nums[j]
                break
            j-=1
        return nums

    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        index=-1
        n=len(nums)
        i=n-2
        while i>=0:
            if(nums[i]<nums[i+1]):
                index=i
                break
            i-=1
        
        if index==-1:
            nums.sort()
            return
        
        self.seclar(nums,index)
        nums[index+1:]=sorted(nums[index+1:])
        return
        