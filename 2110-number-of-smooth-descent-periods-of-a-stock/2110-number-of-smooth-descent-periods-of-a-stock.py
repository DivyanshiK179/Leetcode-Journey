class Solution:
    def getDescentPeriods(self, prices: list[int]) -> int:
        i=0
        n=len(prices)
        count=0
        while(i<n):
            j=i+1
            while(j<n and (prices[j-1]-prices[j])==1):
                j+=1
            l=j-i
            count+=l*(l+1)//2
            i=j
        return count