class Solution:
    def countCommas(self, n: int) -> int:
        if(n<4):
            return 0
        commas=0
        i=1000
        while(i<=n):
            commas+=n-i+1
            i*=1000
        return commas
