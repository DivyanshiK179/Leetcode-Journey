int maxDepth(char* s) {
        int count=0;
        int maxi=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(')
            {
                count+=1;
                maxi=MAX(count,maxi);
            }
            else if(s[i]==')')
            {
                count-=1;
            }
        }
        return maxi;
}