class Solution:
    def ispossible(self, bloomDay: List[int], mid: int, m: int, k:int) -> int:
        bouquet=0
        count=0
        for i in range(len(bloomDay)):
            if(bloomDay[i]<=mid):
                count+=1
                if(count==k):
                    bouquet+=1
                    count=0    
            else:
                count=0
        if(bouquet>=m):
            return True
        return False
        
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if(m*k>len(bloomDay)):
            return -1
        ans=-1
        s=1
        maxi=float('-inf')
        for i in range(len(bloomDay)):
            if(bloomDay[i]>maxi):
                maxi=bloomDay[i]
        e=maxi
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(bloomDay,mid,m,k)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans