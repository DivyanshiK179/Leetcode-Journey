class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        i=0
        j=0
        freq={}
        ans=0
        while(j<len(s)):
            freq[s[j]]=freq.get(s[j],0)+1
            while(freq[s[j]]>2):
                freq[s[i]]-=1
                i+=1
            ans=max(ans,j-i+1)
            j+=1
        return ans