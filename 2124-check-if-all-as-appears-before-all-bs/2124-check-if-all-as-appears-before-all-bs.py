class Solution:
    def checkString(self, s: str) -> bool:
        seenb=False
        for i in range(len(s)):
            if(s[i]=='b'):
                seenb=True
            elif(seenb):
                return False
        return True