class Solution:
    def ispossible(self, ranks: List[int], mid: int, cars: int) -> int:
        c=0
        for i in range(len(ranks)):
            c+=math.isqrt(mid//ranks[i])
            if(c>=cars):
                return True
        return False

    def repairCars(self, ranks: List[int], cars: int) -> int:
        s=1
        minn=min(ranks)
        e=minn*cars*cars
        ans=e
        while(s<=e):
            mid=(s+e)//2
            if(self.ispossible(ranks,mid,cars)):
                ans=mid
                e=mid-1
            else:
                s=mid+1
        return ans