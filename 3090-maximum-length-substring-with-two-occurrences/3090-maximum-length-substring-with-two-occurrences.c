int maximumLengthSubstring(char* s) {
        int i=0;
        int j=0;
        int len=strlen(s);
        int *freq=(int*)calloc(256,sizeof(int));
        int *str=(int*)malloc(len*sizeof(int));
        int ans=0;
        int sum=0;
        for(int i=0;i<len;i++)
        {
            str[i]=s[i];
        }
        while(j<len)
        {
            sum+=str[j];
            freq[str[j]]++;
            while(freq[str[j]]>2)
            {
                freq[str[i]]--;
                i++;
            }
            ans=MAX(ans,j-i+1);
            j++;
        }
        free(freq);
        free(str);
        return ans;
}