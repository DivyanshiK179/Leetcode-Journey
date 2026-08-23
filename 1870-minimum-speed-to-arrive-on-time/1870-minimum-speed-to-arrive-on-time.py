class Solution:
    def ispossible(self, dist: List[int], mid: int, hour: float) -> int:
        h=0
        n=len(dist)
        for i in range(n-1):
            h+=(dist[i]+mid-1)//mid
        h+=dist[n-1]/mid
        if(h<=hour):
            return True
        return False

    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        ans=-1
        s=1
        e=int(1e7)
        while(s<=e):
            mid=s+(e-s)//2
            if(self.ispossible(dist,mid,hour)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans