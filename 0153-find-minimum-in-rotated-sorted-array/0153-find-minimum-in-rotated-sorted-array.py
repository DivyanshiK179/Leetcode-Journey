class Solution:
    def findMin(self, nums: List[int]) -> int:
        s=0
        n=len(nums)
        e=n-1
        minn=float('inf')
        while(s<=e):
            mid=(s+e)//2
            if(nums[mid]<minn):
                minn=nums[mid]
            elif(nums[mid]>nums[e]):
                s=mid+1
            else:
                e=mid-1
        return minn