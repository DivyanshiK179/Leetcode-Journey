class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cBoth = costBoth;
        long long n1 = need1;
        long long n2 = need2;
        
        long long common = min(n1, n2);
        
        long long totalCost = common * min(cBoth, c1 + c2);
    
        long long rem1 = n1 - common;
        long long rem2 = n2 - common;
        
        totalCost += rem1 * min(c1, cBoth);
        
        totalCost += rem2 * min(c2, cBoth);
        
        return totalCost;
    }
};