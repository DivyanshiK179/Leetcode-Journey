class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        min_sum=-1
        for length in range(l,r+1):
            i=0
            j=0
            cur_sum=0
            while(j<len(nums)):
                cur_sum+=nums[j]
                if(j-i+1==length):
                    if(cur_sum>0):
                        if(min_sum==-1 or cur_sum<min_sum):
                            min_sum=cur_sum
                    cur_sum-=nums[i]
                    i+=1
                j+=1
        return min_sum