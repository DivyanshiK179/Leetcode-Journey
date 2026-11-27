#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; ++i) 
        {
            int fi = items[i][0];
            for (int j = 0; j < n; ++j) 
            {
                if (i != j && items[j][0] % fi == 0) 
                {
                    ++freeCount[i];
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) 
        {
            int price = items[i][1];
            int firstGain = 1 + freeCount[i];

            for (int b = budget; b >= price; --b) 
            {
                dp[b] = max(dp[b], dp[b - price] + firstGain);
            }
            for (int b = price; b <= budget; ++b) 
            {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};