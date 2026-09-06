class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefix_sum=0
        suffix_sum=0
        total=0
        for i in range(len(nums)):
            total+=nums[i]
        count=0
        for i in range(len(nums)-1):
            prefix_sum+=nums[i]
            suffix_sum=total-prefix_sum
            if(prefix_sum>=suffix_sum):
                count+=1
        return count