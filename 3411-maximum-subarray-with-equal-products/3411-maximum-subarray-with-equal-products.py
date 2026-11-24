class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        for i in range(n):
            prod=1
            g=0
            l=1
            for j in range(i,n):
                prod*=nums[j]
                l=math.lcm(nums[j],l)
                g=math.gcd(nums[j],g)
                if(prod==l*g):
                    ans=max(ans,j-i+1)
                if(prod>25200):
                    break
        return ans