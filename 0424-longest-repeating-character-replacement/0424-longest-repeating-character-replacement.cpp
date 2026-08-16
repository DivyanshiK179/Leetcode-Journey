class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int len=s.size();
        int max_freq=INT_MIN;
        int max_len=INT_MIN;
        vector<int> freq(256,0);
        while(j<len)
        {
            freq[s[j]]++;
            max_freq=max(max_freq,freq[s[j]]);
            while((j-i+1)-max_freq>k)
            {
                freq[s[i]]--;
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};