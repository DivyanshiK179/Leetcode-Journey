class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxlen=1
        icount=1
        dcount=1
        for i in range(len(nums)-1):
            if(nums[i]<nums[i+1]):
                icount+=1
                dcount=1
            elif(nums[i]>nums[i+1]):
                dcount+=1
                icount=1
            else:
                icount=1
                dcount=1
            maxlen=max({maxlen,icount,dcount})
        return maxlen