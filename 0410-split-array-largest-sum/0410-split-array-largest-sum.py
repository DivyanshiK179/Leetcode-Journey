class Solution:
    def ispossible(self, nums: List[int], mid: int, k: int) -> int:
        summ=0
        c=1
        for i in nums:
            if(summ+i<=mid):
                summ+=i
            else:
                c+=1
                summ=i    
            if(c>k):
                return False
        return True
        
    def splitArray(self, nums: List[int], k: int) -> int:
        total=0
        maxi=0
        for i in range(len(nums)):
            if(nums[i]>maxi):
                maxi=nums[i]
            total+=nums[i]
        s=maxi
        e=total
        ans=e
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(nums,mid,k)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans