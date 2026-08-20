class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s=0
        n=len(nums)
        e=n-1
        while(s<=e):
            mid=(s+e)//2
            if(nums[mid]==target):
                return mid
            if(nums[s]<=nums[mid]):
                if(target>=nums[s] and target<nums[mid]):
                    e=mid-1
                else:
                    s=mid+1
            else:
                if(target<=nums[e] and target>nums[mid]):
                    s=mid+1
                else:
                    e=mid-1
        return -1