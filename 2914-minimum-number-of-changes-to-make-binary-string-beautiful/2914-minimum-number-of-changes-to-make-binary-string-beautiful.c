int minChanges(char* s) {
    int changes=0;
    for(int i=0;i<strlen(s);i+=2) 
    {
        if(s[i]!=s[i+1]) 
        {
            changes++;
        }
    }
    return changes;
}