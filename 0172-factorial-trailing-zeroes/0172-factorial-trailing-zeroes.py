sys.set_int_max_str_digits(100000)
class Solution:
    def trailingZeroes(self, n: int) -> int:
        count=0
        fact=1
        for i in range(2,n+1):
            fact*=i
        f=str(fact)
        for i in range(len(f)-1,-1,-1):
            if(f[i]=='0'):
                count+=1
            else:
                break
        return count