class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i=0
        j=0
        sum=0
        maxi=float('-inf')
        while(j<len(nums)):
            sum+=nums[j]
            if(j-i+1<k):
                j+=1
            elif(j-i+1==k):
                maxi=max(sum,maxi)
                sum-=nums[i]
                j+=1
                i+=1
        return maxi/k