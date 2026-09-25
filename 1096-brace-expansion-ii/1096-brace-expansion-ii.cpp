#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<pair<unordered_set<string>, vector<string>>> st;
        
        unordered_set<string> cur_group;
        vector<string> cur_product = {""};
        
        int n = expression.size();
        int i = 0;
        
        while (i < n) {
            char ch = expression[i];
            
            if (isalpha(ch)) {
                string word = "";
                while (i < n && isalpha(expression[i])) {
                    word += expression[i++];
                }

                vector<string> next_product;
                next_product.reserve(cur_product.size());
                for (const string& p : cur_product) {
                    next_product.push_back(p + word);
                }
                cur_product = move(next_product);
                continue; 
            } 
            else if (ch == '{') {
                st.push({move(cur_group), move(cur_product)});
                cur_group.clear();
                cur_product = {""};
            } 
            else if (ch == ',') {
                for (const string& s : cur_product) {
                    cur_group.insert(s);
                }
                cur_product = {""};
            } 
            else if (ch == '}') {
                for (const string& s : cur_product) {
                    cur_group.insert(s);
                }
                unordered_set<string> inner_set = move(cur_group);
                
                auto [prev_group, prev_product] = move(st.top());
                st.pop();
                cur_group = move(prev_group);
                
                vector<string> next_product;
                next_product.reserve(prev_product.size() * inner_set.size());
                for (const string& p : prev_product) {
                    for (const string& item : inner_set) {
                        next_product.push_back(p + item);
                    }
                }
                cur_product = move(next_product);
            }
            
            i++;
        }
        
        for (const string& s : cur_product) {
            cur_group.insert(s);
        }
    
        vector<string> result(cur_group.begin(), cur_group.end());
        sort(result.begin(), result.end());
        return result;
    }
};