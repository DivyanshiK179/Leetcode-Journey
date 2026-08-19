class Solution:
    def ispossible(self, position: List[int], mid:int , m:int) -> int:
        ball=1
        pos=position[0]
        for i in range(1,len(position)):
            if(position[i]-pos>=mid):
                ball+=1
                pos=position[i]
            if(ball==m):
                return True
        return False
        
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        ans=-1
        s=1
        n=len(position)
        e=position[n-1]-position[0]
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(position,mid,m)):
                ans=mid
                s=mid+1
            else:
                e=mid-1
        return ans