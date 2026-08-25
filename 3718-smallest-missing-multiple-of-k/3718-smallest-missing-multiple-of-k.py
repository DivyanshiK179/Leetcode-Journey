class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        freq=[0]*10005
        for i in range(len(nums)):
            freq[nums[i]]+=1
        j=1
        while True:
            prod=k*j
            if(freq[prod]==0):
                return prod
            j+=1