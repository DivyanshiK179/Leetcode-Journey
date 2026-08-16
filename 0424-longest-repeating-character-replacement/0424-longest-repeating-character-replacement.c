int characterReplacement(char* s, int k) {
        int i=0;
        int j=0;
        int len=strlen(s);
        int max_freq=INT_MIN;
        int max_len=INT_MIN;
        int freq[256]={0};
        while(j<len)
        {
            freq[s[j]]++;
            max_freq=MAX(max_freq,freq[s[j]]);
            while((j-i+1)-max_freq>k)
            {
                freq[s[i]]--;
                i++;
            }
            max_len=MAX(max_len,j-i+1);
            j++;
        }
        return max_len;
}