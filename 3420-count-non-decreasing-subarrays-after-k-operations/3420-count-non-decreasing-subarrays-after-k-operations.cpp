class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        
        deque<pair<long long, long long>> dq;
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) 
        {
            long long cur = nums[l];
            long long cnt = 1;
            
            while (!dq.empty() && dq.back().first < cur) 
            {
                auto [val, c] = dq.back();
                dq.pop_back();
                cost += (cur - val) * c;
                cnt += c;
            }
            dq.push_back({cur, cnt});
            while (cost > k) 
            {
                auto& [val, c] = dq.front();
                cost -= (val - nums[r]);
                --c;
                if (c == 0) {
                    dq.pop_front();
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};