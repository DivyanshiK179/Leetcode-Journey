class Solution:
    def reverseDegree(self, s: str) -> int:
        total = 0
        for i in range(0,len(s)):
            reversePos=ord('z')-ord(s[i])+1
            stringPos=i+1
            total+=reversePos*stringPos
        return total