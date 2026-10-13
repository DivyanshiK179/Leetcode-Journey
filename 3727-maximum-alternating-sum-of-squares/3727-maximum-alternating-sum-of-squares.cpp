#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        
        for (int i = 0; i < n; ++i) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        
        sort(sq.begin(), sq.end());
        
        long long ans = 0;
        int neg_count = n / 2;
        
        for (int i = 0; i < neg_count; ++i) {
            ans -= sq[i];
        }
        
        for (int i = neg_count; i < n; ++i) {
            ans += sq[i];
        }
        
        return ans;
    }
};