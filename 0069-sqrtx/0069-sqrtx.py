class Solution:
    def mySqrt(self, x: int) -> int:
        s=0
        e=x
        ans=0
        while(s<=e):
            mid=(s+e)//2
            sq=mid*mid
            if(sq==x):
                return mid
            elif(sq<x):
                ans=mid
                s=mid+1
            else:
                e=mid-1
        return ans