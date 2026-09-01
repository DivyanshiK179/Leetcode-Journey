class Solution:
    def solve(self, n: int, i: int) -> bool:
        if(pow(2,i)==n):
            return True
        if(pow(2,i)>n):
            return False
        return self.solve(n,i+1)
        
    def isPowerOfTwo(self, n: int) -> bool:  
        if(n<=0):
            return False
        return self.solve(n,0)
