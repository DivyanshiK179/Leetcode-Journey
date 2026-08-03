class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i=0
        j=0
        summ=0
        score=0
        count=0
        while(j<len(nums)):
            summ+=nums[j]
            score=summ*(j-i+1)
            while(score>=k and i<=j):
                summ-=nums[i]
                i+=1
                score=summ*(j-i+1)
            count+=(j-i+1)
            j+=1
        return count