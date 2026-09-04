class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        for i in range(len(nums)):
            max=nums[0]
            for j in range(0,i+1):
                if(nums[j]>max):
                    max=nums[j]
            min=nums[i]
            for l in range(i,len(nums)):
                if(nums[l]<min):
                    min=nums[l]
            if((max-min)<=k):
                return i
        return -1
