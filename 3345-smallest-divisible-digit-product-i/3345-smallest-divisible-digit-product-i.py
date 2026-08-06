class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n,n+10):
            prod=1
            temp=i
            while(temp>0):
                dig=temp%10
                prod*=dig
                temp=temp//10
            if(prod%t==0):
                    break
        return i
