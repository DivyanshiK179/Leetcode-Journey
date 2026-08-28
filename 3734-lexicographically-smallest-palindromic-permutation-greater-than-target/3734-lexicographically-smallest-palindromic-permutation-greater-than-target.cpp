#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int m = n / 2;
        
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int odd_count = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        
        if (odd_count > 1 || (n % 2 == 0 && odd_count > 0)) {
            return "";
        }
        
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }
        
        auto build_palindrome = [&](const string& first_half) -> string {
            string pal = first_half;
            if (n % 2 != 0) {
                pal += mid_char;
            }
            for (int i = m - 1; i >= 0; --i) {
                pal += first_half[i];
            }
            return pal;
        };
        
        string best = "";
        
        bool can_match_target_prefix = true;
        vector<int> cur_count = half_count;
        for (int i = 0; i < m; ++i) {
            int c = target[i] - 'a';
            if (cur_count[c] > 0) {
                cur_count[c]--;
            } else {
                can_match_target_prefix = false;
                break;
            }
        }
        
        if (can_match_target_prefix) {
            string p_same = build_palindrome(target.substr(0, m));
            if (p_same > target) {
                best = p_same;
            }
        }
        
        vector<int> prefix_counts = half_count;
        string prefix = "";
        
        for (int i = 0; i < m; ++i) {
            for (char c = target[i] + 1; c <= 'z'; ++c) {
                if (prefix_counts[c - 'a'] > 0) {
                    vector<int> rem = prefix_counts;
                    rem[c - 'a']--;
                    
                    string first_half = prefix;
                    first_half += c;
                    
                    for (int ch = 0; ch < 26; ++ch) {
                        while (rem[ch] > 0) {
                            first_half += (char)('a' + ch);
                            rem[ch]--;
                        }
                    }
                    
                    string cand = build_palindrome(first_half);
                    if (cand > target) {
                        if (best.empty() || cand < best) {
                            best = cand;
                        }
                    }
                }
            }
            
            int target_c = target[i] - 'a';
            if (prefix_counts[target_c] > 0) {
                prefix_counts[target_c]--;
                prefix += target[i];
            } else {
                break;
            }
        }
        
        return best;
    }
};