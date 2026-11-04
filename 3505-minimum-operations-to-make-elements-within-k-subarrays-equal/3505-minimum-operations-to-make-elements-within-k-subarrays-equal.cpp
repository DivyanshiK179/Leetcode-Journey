#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    multiset<long long> left_set, right_set;
    long long sum_left = 0, sum_right = 0;
    int target_left_size;

    void balance() {
        while ((int)left_set.size() < target_left_size && !right_set.empty()) {
            auto it = right_set.begin();
            long long val = *it;
            right_set.erase(it);
            sum_right -= val;
            left_set.insert(val);
            sum_left += val;
        }
        while ((int)left_set.size() > target_left_size) {
            auto it = prev(left_set.end());
            long long val = *it;
            left_set.erase(it);
            sum_left -= val;
            right_set.insert(val);
            sum_right += val;
        }
    }

    void add(long long val) {
        if (left_set.empty() || val <= *left_set.rbegin()) {
            left_set.insert(val);
            sum_left += val;
        } else {
            right_set.insert(val);
            sum_right += val;
        }
        balance();
    }

    void remove(long long val) {
        auto it = left_set.find(val);
        if (it != left_set.end()) {
            left_set.erase(it);
            sum_left -= val;
        } else {
            it = right_set.find(val);
            if (it != right_set.end()) {
                right_set.erase(it);
                sum_right -= val;
            }
        }
        balance();
    }

    long long get_cost() {
        long long median = *left_set.rbegin();
        long long cost_left = (long long)left_set.size() * median - sum_left;
        long long cost_right = sum_right - (long long)right_set.size() * median;
        return cost_left + cost_right;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        target_left_size = (x + 1) / 2;

        left_set.clear();
        right_set.clear();
        sum_left = 0;
        sum_right = 0;

        vector<long long> cost(n, 0);

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i] = get_cost();
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};