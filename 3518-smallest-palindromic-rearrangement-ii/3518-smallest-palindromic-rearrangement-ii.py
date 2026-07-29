import math

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        n = len(s)
        half_len = n // 2
        
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        mid_char = ""
        half_counts = {}
        for char, count in freq.items():
            if count % 2 == 1:
                mid_char = char
            half_counts[char] = count // 2

        def count_permutations(counts, total_len):
            res = 1
            curr_len = total_len
            for c in sorted(counts.keys()):
                cnt = counts[c]
                if cnt > 0:
                    res = res * math.comb(curr_len, cnt)
                    curr_len -= cnt
                    if res > k: 
                        return k + 1
            return res
        
        total_possible = count_permutations(half_counts, half_len)
        if total_possible < k:
            return ""
        
        first_half = []
        
        for pos in range(half_len):
            remaining_len = half_len - 1 - pos
            
            for ch_code in range(ord('a'), ord('z') + 1):
                ch = chr(ch_code)
                if half_counts.get(ch, 0) > 0:
                    half_counts[ch] -= 1
                    
                    ways = count_permutations(half_counts, remaining_len)
                    
                    if ways >= k:
                        first_half.append(ch)
                        break  
                    else:
                        k -= ways
                        half_counts[ch] += 1  

        first_half_str = "".join(first_half)
        return first_half_str + mid_char + first_half_str[::-1]