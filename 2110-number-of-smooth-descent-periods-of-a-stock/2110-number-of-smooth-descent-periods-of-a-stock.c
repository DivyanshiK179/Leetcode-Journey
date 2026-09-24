long long getDescentPeriods(int* prices, int pricesSize) {
        int i=0;
        int n=pricesSize;
        long long count=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n && (prices[j-1]-prices[j])==1)
            {
                j++;
            }
            long long l=j-i;
            count+=l*(l+1)/2;
            i=j;
        }
        return count;
}