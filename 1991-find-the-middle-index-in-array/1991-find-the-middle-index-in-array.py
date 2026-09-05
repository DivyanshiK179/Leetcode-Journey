class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        prefix_sum=0
        total=0
        for i in range(len(nums)):
            total+=nums[i]
        for i in range(len(nums)):
            if(total-prefix_sum-nums[i]==prefix_sum):
                return i
            prefix_sum+=nums[i]
        return -1