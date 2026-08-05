int lengthOfLongestSubstring(char* s) {
        int *freq=(int*)malloc(256*sizeof(int));
        for(int i=0;i<256;i++)
        {
            freq[i]=0;
        }
        int j=0;
        int i=0;
        int max_win=0;
        while(j<strlen(s))
        {
            while(freq[s[j]]==1)
            {
                freq[s[i]]=0;
                i++;
            }
            freq[s[j]]=1;
            int cur_win=j-i+1;
            max_win=MAX(max_win,cur_win);
            j++;
        }
        return max_win;
}