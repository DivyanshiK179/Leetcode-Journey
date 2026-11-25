#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return n;

        const long long BASE1 = 100003LL;
        const long long MOD1 = 1000000007LL;
        const long long BASE2 = 100019LL;
        const long long MOD2 = 1000000009LL;

        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) 
        {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        auto hasUnique = [&](int len) -> bool 
        {
            if (len <= 0 || len > n) return false;

            long long h1 = 0, h2 = 0;
            for (int i = 0; i < len; ++i) 
            {
                long long val = nums[i];
                h1 = (h1 * BASE1 + val) % MOD1;
                h2 = (h2 * BASE2 + val) % MOD2;
            }

            unordered_map<unsigned long long, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);

            auto pack = [](long long a, long long b) -> unsigned long long 
            {
                return (static_cast<unsigned long long>(a) << 32) | static_cast<unsigned long long>(b);
            };

            freq[pack(h1, h2)]++;

            long long p1 = pow1[len];
            long long p2 = pow2[len];

            for (int i = len; i < n; ++i) 
            {
                long long outVal = nums[i - len];
                long long inVal = nums[i];

                h1 = (h1 * BASE1 + inVal - (outVal * p1) % MOD1 + MOD1) % MOD1;
                h2 = (h2 * BASE2 + inVal - (outVal * p2) % MOD2 + MOD2) % MOD2;

                freq[pack(h1, h2)]++;
            }

            for (const auto& [_, count] : freq) 
            {
                if (count == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) 
            {
                ans = mid;
                hi = mid - 1;
            } 
            else 
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};