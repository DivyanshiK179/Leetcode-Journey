#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<vector<int>> new_adj(n);
        vector<int> last_seen(26, -1);

        auto buildNewTree = [&](auto& self, int u) -> void {
            if (u != 0) {
                int c = s[u] - 'a';
                int target_parent = (last_seen[c] != -1) ? last_seen[c] : parent[u];
                new_adj[target_parent].push_back(u);
            }

            int c = s[u] - 'a';
            int prev_node = last_seen[c];
            last_seen[c] = u;

            for (int v : orig_adj[u]) {
                self(self, v);
            }

            last_seen[c] = prev_node; 
        };

        buildNewTree(buildNewTree, 0);

        vector<int> ans(n, 1);
        auto computeSizes = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : new_adj[u]) {
                size += self(self, v);
            }
            return ans[u] = size;
        };

        computeSizes(computeSizes, 0);
        return ans;
    }
};