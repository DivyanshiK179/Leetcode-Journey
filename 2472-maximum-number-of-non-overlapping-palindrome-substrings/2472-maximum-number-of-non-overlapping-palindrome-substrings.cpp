class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int last_end = -1;

        auto is_palindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int r = k - 1; r < n; ++r) {
            if (r - k + 1 > last_end && is_palindrome(r - k + 1, r)) {
                ans++;
                last_end = r;
            }
            else if (r - k > last_end && is_palindrome(r - k, r)) {
                ans++;
                last_end = r;
            }
        }

        return ans;
    }
};