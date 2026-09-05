class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        high=0
        height=0
        for i in range(len(gain)):
            height+=gain[i]
            high=max(high,height)
        return high