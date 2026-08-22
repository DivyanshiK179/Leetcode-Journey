class Solution:
    def ispossible(self, time: List[int], mid: int, totalTrips: int) -> int:
        t=0
        for i in range(len(time)):
            t+=mid//time[i]
            if(t>=totalTrips):
                return True
        return False
        
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        ans=-1
        s=1
        minn=0
        for i in range(len(time)):
            if(minn<time[i]):
                minn=time[i]
        e=minn*totalTrips
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(time,mid,totalTrips)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans