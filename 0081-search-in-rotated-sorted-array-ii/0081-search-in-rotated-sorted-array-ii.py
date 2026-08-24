class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        s=0
        n=len(nums)
        e=n-1
        while(s<=e):           
            mid=s+(e-s)//2
            if(nums[mid]==target):
                return True
            if(nums[s]==nums[mid] and nums[mid]==nums[e]):
                s+=1
                e-=1
            elif(nums[mid]>=nums[s]):
                if(target>=nums[s] and target<nums[mid]):
                    e=mid-1
                else:
                    s=mid+1
            else:
                if(target<=nums[e] and target>nums[mid]):
                    s=mid+1
                else:
                    e=mid-1
        return False