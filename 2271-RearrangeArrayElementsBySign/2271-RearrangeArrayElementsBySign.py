# Last updated: 10/27/2025, 7:05:59 PM
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        l=len(nums)
        list1=[]
        list2=[]
        for i in range(0,l):
            if nums[i]>=0:
                list1.append(nums[i])
            else:
                list2.append(nums[i])
        
        k=0
        for i in range(0,len(list1)):
            nums[k]=list1[i]
            k+=1
            nums[k]=list2[i]
            k+=1

        return nums
            