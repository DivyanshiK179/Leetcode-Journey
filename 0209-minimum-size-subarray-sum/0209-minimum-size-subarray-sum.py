class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i=0
        j=0
        summ=0
        minn=float('inf')
        while(j<len(nums)):
            summ+=nums[j]
            while(summ>=target):
                minn=min(j-i+1,minn)
                summ-=nums[i]
                i+=1
            j+=1
        if(minn==float('inf')):
            return 0
        else:
            return minn