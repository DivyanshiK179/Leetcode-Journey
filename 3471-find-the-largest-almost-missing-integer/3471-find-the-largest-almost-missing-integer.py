class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        subarray_count=[0]*(51)
        freq=[0]*(51)
        i=0
        j=0
        maxi=-1
        n=len(nums)
        while(j<n):
            freq[nums[j]]+=1
            if(j-i+1==k):
                for c in range(0,51):
                    if(freq[c]>0):
                        subarray_count[c]+=1
                freq[nums[i]]-=1
                i+=1
            j+=1
        for d in range(0,51):
            if(subarray_count[d]==1):
                maxi=max(maxi,d)
        return maxi