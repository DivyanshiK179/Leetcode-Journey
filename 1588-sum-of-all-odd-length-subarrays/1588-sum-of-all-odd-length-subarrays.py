class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans=0
        n=len(arr)
        for i in range(n):
            summ=0
            for j in range(i,n):
                summ+=arr[j]
                if((j-i+1)%2!=0):
                    ans+=summ
        return ans