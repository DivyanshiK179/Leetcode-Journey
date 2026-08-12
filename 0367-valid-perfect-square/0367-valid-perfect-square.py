class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        s=1
        e=num
        while(s<=e):
            m=(s+e)//2
            mid=m*m
            if(mid==num):
                return True
            elif(mid<num):
                s=m+1
            else:
                e=m-1
        return False