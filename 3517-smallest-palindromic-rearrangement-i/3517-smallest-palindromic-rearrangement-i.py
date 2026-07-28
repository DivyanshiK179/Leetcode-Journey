class Solution:
    def smallestPalindrome(self, s: str) -> str:
        half=len(s)//2
        first_half="".join(sorted(s[:half]))
        if(len(s)%2!=0):
            mid=s[half]
            return first_half+mid+first_half[::-1]
        return first_half+first_half[::-1]