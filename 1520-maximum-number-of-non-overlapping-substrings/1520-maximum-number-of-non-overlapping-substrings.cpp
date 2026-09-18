#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        auto getRight = [&](int i) -> int {
            int right = last[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                int c = s[j] - 'a';
                if (first[c] < i) return -1;
                right = max(right, last[c]);
            }
            return right;
        };

        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; ++i) {
            if (i == first[s[i] - 'a']) {
                int right = getRight(i);
                if (right != -1) {
                    intervals.push_back({right, i});
                }
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prevEnd = -1;
        for (const auto& [end, start] : intervals) {
            if (start > prevEnd) {
                result.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return result;
    }
};