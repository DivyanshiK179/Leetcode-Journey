#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    bool isBetter(long long weightA, const vector<int>& idxA, 
                  long long weightB, const vector<int>& idxB) {
        if (weightB != weightA) {
            return weightB > weightA;
        }
        return idxB < idxA; 
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        vector<int> r_ends(n);
        for (int i = 0; i < n; ++i) {
            r_ends[i] = arr[i].r;
        }

        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));

        for (int i = 1; i <= n; ++i) {
            int cur_l = arr[i - 1].l;
            int cur_wt = arr[i - 1].weight;
            int cur_id = arr[i - 1].id;

            int j = lower_bound(r_ends.begin(), r_ends.end(), cur_l) - r_ends.begin();

            for (int k = 1; k <= 4; ++k) {
                long long best_wt = dp[k][i - 1].first;
                vector<int> best_idx = dp[k][i - 1].second;

                long long cand_wt = dp[k - 1][j].first + cur_wt;
                vector<int> cand_idx = dp[k - 1][j].second;
            
                cand_idx.insert(lower_bound(cand_idx.begin(), cand_idx.end(), cur_id), cur_id);

                if (isBetter(best_wt, best_idx, cand_wt, cand_idx)) {
                    dp[k][i] = {cand_wt, move(cand_idx)};
                } else {
                    dp[k][i] = {best_wt, move(best_idx)};
                }
            }
        }

        long long max_score = -1;
        vector<int> result;

        for (int k = 1; k <= 4; ++k) {
            if (isBetter(max_score, result, dp[k][n].first, dp[k][n].second)) {
                max_score = dp[k][n].first;
                result = dp[k][n].second;
            }
        }

        return result;
    }
};