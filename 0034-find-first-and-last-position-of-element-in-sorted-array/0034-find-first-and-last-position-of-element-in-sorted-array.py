def lower_bound(nums,target,size):
    s=0
    e=size-1
    ans=-1
    while(s<=e):
        mid=(s+e)//2
        if(nums[mid]==target):
            ans=mid
            e=mid-1
        elif(nums[mid]<target):
            s=mid+1
        else:
            e=mid-1
    return ans 

def upper_bound(nums,target,size):
    s=0
    e=size-1
    ans=-1
    while(s<=e):
        mid=(s+e)//2
        if(nums[mid]==target):
            ans=mid
            s=mid+1
        elif(nums[mid]<target):
            s=mid+1
        else:
            e=mid-1
    return ans 

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res=[]
        size=len(nums)
        l=lower_bound(nums,target,size)
        res.append(l)
        u=upper_bound(nums,target,size)
        res.append(u)
        return res