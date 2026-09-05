class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n=len(arr)
        suffix_max=-1
        for i in range(n-1,-1,-1):
            cur=arr[i]
            arr[i]=suffix_max
            suffix_max=max(suffix_max,cur)
        return arr