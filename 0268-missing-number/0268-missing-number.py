class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        freq=[0]*(n+1)
        for i in range(n):
            freq[nums[i]]+=1
        for i in range(n+1):
            if(freq[i]==0):
                return i
        return -1