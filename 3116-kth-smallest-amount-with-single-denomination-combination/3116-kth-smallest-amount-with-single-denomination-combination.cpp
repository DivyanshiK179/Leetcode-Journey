#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        auto countMultiples = [&](long long target) -> long long {
            long long count = 0;
            int totalSubsets = 1 << n;
            
            for (int mask = 1; mask < totalSubsets; ++mask) {
                long long currentLcm = 1;
                int bits = 0;
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        bits++;
                        currentLcm = std::lcm(currentLcm, (long long)coins[i]);
                        if (currentLcm > target) break;
                    }
                }
                
                if (currentLcm <= target) {
                    if (bits % 2 == 1) {
                        count += target / currentLcm;
                    } else {
                        count -= target / currentLcm;
                    }
                }
            }
            return count;
        };

        long long left = 1;
        long long minCoin = *std::min_element(coins.begin(), coins.end());
        long long right = minCoin * k;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};