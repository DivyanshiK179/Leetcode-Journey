#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;

        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) 
        {
            for (int d = 1; d < len; ++d) 
            {
                if (len % d == 0) divisors[len].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int len = j - i + 1;
                int best = INF;
                for (int d : divisors[len]) 
                {
                    int changes = 0;
                    int m = len / d; 
                    for (int r = 0; r < d; ++r) 
                    {
                        for (int a = 0; a < m / 2; ++a) 
                        {
                            int left = i + r + a * d;
                            int right = i + r + (m - 1 - a) * d;
                            if (s[left] != s[right]) changes++;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= k && j <= i / 2; ++j) 
            {
                for (int p = 2 * (j - 1); p <= i - 2; ++p) 
                {
                    if (dp[p][j - 1] == INF || cost[p][i - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};