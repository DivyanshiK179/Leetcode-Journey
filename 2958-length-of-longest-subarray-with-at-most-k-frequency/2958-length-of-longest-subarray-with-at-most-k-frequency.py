class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq=defaultdict(int)
        i=0
        max_size=0
        for j in range(len(nums)):
            freq[nums[j]]+=1
            while(freq[nums[j]]>k):
                freq[nums[i]]-=1
                i+=1
            cur_size=j-i+1
            max_size=max(max_size,cur_size)
        return max_size