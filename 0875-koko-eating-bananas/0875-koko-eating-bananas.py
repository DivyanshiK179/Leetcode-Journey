class Solution:
    def ispossible(self, piles: List[int], mid: int, h: int) -> bool:
        hour=0
        for i in range(len(piles)):
            if(piles[i]<=mid):
                hour+=1
            elif(piles[i]%mid==0):
                hour+=(piles[i]//mid)
            elif(piles[i]%mid!=0):
                hour+=(piles[i]//mid)+1
            if(hour>h):
                return False
        return True
        
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ans=-1
        s=1
        maxi=float('-inf')
        for i in range(len(piles)):
            if(piles[i]>maxi):
                maxi=piles[i]
        e=maxi
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(piles,mid,h)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans