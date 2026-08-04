class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        res=[]
        minn=min(nums)
        maxx=max(nums)
        for i in range(minn,maxx):
            if(i not in nums):
                res.append(i)
        return res