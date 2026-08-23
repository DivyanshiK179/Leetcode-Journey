class Solution:
    def ispossible(self, nums: List[int], mid: int, p: int) -> int:
        maxx=0
        pair=0
        i=0
        while(i<len(nums)-1):
            if(abs(nums[i+1]-nums[i])<=mid):
                pair+=1 
                i+=2
            else:
                i+=1
        if(pair>=p):
            return True
        return False

    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        ans=0
        s=0
        e=nums[len(nums)-1]-nums[0]
        while(s<=e):
            mid=s+(e-s)//2
            if(self.ispossible(nums,mid,p)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans