class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1_ind=0
        max2=float('-inf')
        for i in range(len(nums)):
            if(nums[i]>nums[max1_ind]):
                max1_ind=i
        for j in range(len(nums)):
            if(nums[j]>max2 and j!=max1_ind):
                max2=nums[j]
        return((nums[max1_ind]-1)*(max2-1))
