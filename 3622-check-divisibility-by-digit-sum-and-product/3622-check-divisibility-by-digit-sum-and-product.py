class Solution:
    def checkDivisibility(self, n: int) -> bool:
        temp=n
        summ=0
        prod=1
        total=0
        while(temp>0):
            dig=temp%10
            summ+=dig
            prod*=dig
            temp//=10
        total=summ+prod
        if(n%total==0):
            return True
        return False