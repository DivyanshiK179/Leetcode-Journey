class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i=0
        j=0
        max_win=-1
        while(j<len(nums)):
            if(nums[j]==0):
                k-=1
            while(k==-1):
                if(nums[i]==0):
                    k+=1
                i+=1
            curr_win=j-i+1
            max_win=max(max_win,curr_win)
            j+=1
        return max_win