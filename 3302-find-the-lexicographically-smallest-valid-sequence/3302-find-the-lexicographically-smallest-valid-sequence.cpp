#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();

        std::vector<int> last(m + 1, -1);
        last[m] = n;

        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--;
            } else {
                break;
            }
        }

        std::vector<int> res;
        bool changed = false;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            if (j == m) {
                break;
            }

            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } 
            else {
                if (!changed && last[j + 1] > i) {
                    res.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }

        return res.size() == m ? res : std::vector<int>();
    }
};