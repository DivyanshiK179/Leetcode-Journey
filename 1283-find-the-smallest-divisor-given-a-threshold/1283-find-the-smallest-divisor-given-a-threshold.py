class Solution:
    def ispossible(self, nums: List[int], mid: int, threshold: int) -> int:
        summ=0
        for i in range(len(nums)):
            if(nums[i]%mid==0):
                summ+=(nums[i]//mid)
            else:
                summ+=(nums[i]//mid)+1
        if(summ<=threshold):
            return True
        return False

    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        ans=-1
        s=1
        maxi=float('-inf')
        for i in range(len(nums)):
            if(nums[i]>maxi):
                maxi=nums[i]
        e=maxi
        while(s<=e):
            mid=s+(e-s)//2
            if(self.ispossible(nums,mid,threshold)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans