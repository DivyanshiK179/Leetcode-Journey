int countCommas(int n) {
        if(n<1000)
        {
            return 0;
        }
        int commas=0;
        for(int i=1000;i<=n;i++)
        {
            commas+=1;
        }
        return commas;
}