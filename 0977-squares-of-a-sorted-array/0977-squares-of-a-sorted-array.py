class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        i=0
        j=len(nums)-1
        k=len(nums)-1
        res=[0]*len(nums)
        while(i<=j):
            if(abs(nums[i])<abs(nums[j])):
                res[k]=nums[j]*nums[j]
                k-=1
                j-=1
            else:
                res[k]=nums[i]*nums[i]
                k-=1
                i+=1
        return res