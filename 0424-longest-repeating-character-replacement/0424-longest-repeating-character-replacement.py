class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        i=0
        j=0
        l=len(s)
        max_freq=float('-inf')        
        max_len=float('-inf')
        freq={}
        while(j<l):
            freq[s[j]]=freq.get(s[j],0)+1
            max_freq=max(max_freq,freq[s[j]])
            while((j-i+1)-max_freq>k):
                freq[s[i]]-=1
                i+=1
            max_len=max(max_len,j-i+1)
            j+=1
        return max_len