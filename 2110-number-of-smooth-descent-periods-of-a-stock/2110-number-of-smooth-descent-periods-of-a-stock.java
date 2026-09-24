class Solution {
    public long getDescentPeriods(int[] prices) {
        int i=0;
        int n=prices.length;
        long count=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n && (prices[j-1]-prices[j])==1)
            {
                j++;
            }
            long l=j-i;
            count+=l*(l+1)/2;
            i=j;
        }
        return count;
    }
}