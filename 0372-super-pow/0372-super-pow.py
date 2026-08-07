class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        r=0
        for i in b:
            r=r*10+i
        return pow(a,r,1337)