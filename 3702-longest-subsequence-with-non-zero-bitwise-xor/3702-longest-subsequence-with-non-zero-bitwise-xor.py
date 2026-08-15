class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        total_xor=0
        has_nz=0
        n=len(nums)
        for i in range(n):
            total_xor^=nums[i]
            if(nums[i]!=0):
                has_nz=1
        if(total_xor!=0):
            return n
        elif(has_nz):
            return n-1    
        return 0