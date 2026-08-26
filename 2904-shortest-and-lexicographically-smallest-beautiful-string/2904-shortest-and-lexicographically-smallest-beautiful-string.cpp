#include <string>
#include <vector>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        std::vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        
        if (ones.size() < k) {
            return "";
        }
        
        std::string result = "";
        
        for (size_t i = 0; i + k - 1 < ones.size(); ++i) {
            int left = ones[i];
            int right = ones[i + k - 1];
            std::string candidate = s.substr(left, right - left + 1);
            
            if (result.empty() || 
                candidate.length() < result.length() || 
                (candidate.length() == result.length() && candidate < result)) {
                result = candidate;
            }
        }
        
        return result;
    }
};