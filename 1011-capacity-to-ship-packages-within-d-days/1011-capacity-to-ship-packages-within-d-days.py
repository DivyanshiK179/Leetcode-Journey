class Solution:
    def ispossible(self,weights:List[int],mid:int,days:int)->bool:
        day=1
        ship_load=0
        for i in range(len(weights)):
            if(ship_load+weights[i]<=mid):
                ship_load+=weights[i]
                i+=1
            else:
                day+=1
                ship_load=weights[i]
            if(day>days):
                return False           
        return True

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        ans=0
        total=sum(weights)
        s=max(weights)
        e=total
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(weights,mid,days)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans