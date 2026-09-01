class Solution:
    def solve(self, n: int, mem: List[int]) -> int:
        if(n<=2):
            return n
        if(mem[n]!= -1):
            return mem[n]
        mem[n]=self.solve(n-1,mem)+self.solve(n-2,mem)
        return mem[n]
        
    def climbStairs(self, n: int) -> int:
        mem=[-1]*(n+1)
        return self.solve(n, mem)