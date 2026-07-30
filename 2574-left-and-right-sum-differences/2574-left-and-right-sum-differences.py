class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left=0
        right=0
        answer=[]
        leftSum=[0]*(len(nums))
        rightSum=[0]*(len(nums))
        for i in range(0,len(nums)):
            leftSum[i]=left
            left+=nums[i]
        for i in range(len(nums)-1,-1,-1):
            rightSum[i]=right
            right+=nums[i]
        rightSum[-1]=0
        for i in range(len(nums)):
            answer.append(abs(leftSum[i]-rightSum[i]))
        return answer