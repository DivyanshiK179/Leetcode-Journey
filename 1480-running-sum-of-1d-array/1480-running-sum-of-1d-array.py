class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        res=[0]*len(nums)
        running_sum=0
        for i in range(len(nums)):
            running_sum+=nums[i]
            res[i]=running_sum        
        return res