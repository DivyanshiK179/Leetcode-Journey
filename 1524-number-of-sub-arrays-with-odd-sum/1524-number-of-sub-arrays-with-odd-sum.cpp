class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        long long odd_count = 0;
        long long even_count = 1;
        long long current_sum = 0;
        long long ans = 0;
        
        for (int num : arr) 
        {
            current_sum += num;
            if (current_sum % 2 != 0) 
            {
                ans = (ans + even_count) % MOD;
                odd_count++;
            } 
            else 
            {
                ans = (ans + odd_count) % MOD;
                even_count++;
            }
        }
        
        return ans;
    }
};