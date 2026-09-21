#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int v = num % k;

            next_dp[v]++;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * v) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};