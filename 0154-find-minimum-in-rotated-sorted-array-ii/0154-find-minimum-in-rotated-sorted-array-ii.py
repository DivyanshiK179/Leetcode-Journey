class Solution:
    def findMin(self, nums: List[int]) -> int:
        s=0
        n=len(nums)
        e=n-1
        minn=float('inf')
        while(s<=e):
            mid=s+(e-s)//2
            if(nums[mid]<minn):
                minn=nums[mid]
            if(nums[mid]>nums[e]):
                s=mid+1
            elif(nums[mid]<nums[e]):
                e=mid-1
            else:
                e-=1
        return minn