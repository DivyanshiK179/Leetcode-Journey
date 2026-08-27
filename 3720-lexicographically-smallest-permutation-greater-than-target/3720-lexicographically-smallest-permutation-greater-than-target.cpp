class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> countS(26, 0);
        for (char c : s) {
            countS[c - 'a']++;
        }

        for (int L = n - 1; L >= 0; --L) {
            vector<int> remCount = countS;
            bool canFormPrefix = true;

            for (int i = 0; i < L; ++i) {
                int charIdx = target[i] - 'a';
                if (--remCount[charIdx] < 0) {
                    canFormPrefix = false;
                    break;
                }
            }

            if (!canFormPrefix) continue;

            int targetCharIdx = target[L] - 'a';
            int bestCharIdx = -1;
            for (int c = targetCharIdx + 1; c < 26; ++c) {
                if (remCount[c] > 0) {
                    bestCharIdx = c;
                    break;
                }
            }

            if (bestCharIdx != -1) {
                string result = target.substr(0, L);
                result += (char)('a' + bestCharIdx);
                remCount[bestCharIdx]--;

                for (int c = 0; c < 26; ++c) {
                    while (remCount[c] > 0) {
                        result += (char)('a' + c);
                        remCount[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};