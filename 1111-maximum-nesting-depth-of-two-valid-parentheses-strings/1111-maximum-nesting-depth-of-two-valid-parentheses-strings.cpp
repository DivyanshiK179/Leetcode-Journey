#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans;
        ans.reserve(seq.size());
        int depth=0;
        
        for (char ch:seq) {
            if (ch=='(') 
            {
                depth++;
                ans.push_back(depth%2);
            } 
            else 
            {
                ans.push_back(depth%2);
                depth--;
            }
        }
        
        return ans;
    }
};