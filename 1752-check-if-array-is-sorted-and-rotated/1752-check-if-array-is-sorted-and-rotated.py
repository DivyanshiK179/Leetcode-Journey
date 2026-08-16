class Solution:
    def check(self, nums: List[int]) -> bool:
        A=sorted(nums)
        for x in range(len(nums)):
            is_match=True
            for i in range(len(nums)):
                if(A[i]!=nums[(i+x)%len(nums)]):
                    is_match=False
                    break
            if(is_match):
                return True
        return False
