class Solution:
    def solve(self, nums: List[int], temp: List[int], output: List[List[int]], i: int):
        if(i==len(nums)):
            output.append(temp.copy())
            return
        self.solve(nums,temp,output,i+1)
        temp.append(nums[i])
        self.solve(nums,temp,output,i+1)
        temp.pop()  

    def subsets(self, nums: List[int]) -> List[List[int]]:
        output=[]
        temp=[]
        self.solve(nums,temp,output,0)
        return output