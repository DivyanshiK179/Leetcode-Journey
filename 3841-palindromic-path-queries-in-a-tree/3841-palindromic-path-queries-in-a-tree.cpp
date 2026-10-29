#include <vector>
#include <string>

using namespace std;

class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> bit;
    int n_nodes;

    void dfs(int u, int p, int d) {
        tin[u] = ++timer;
        up[u][0] = p;
        depth[u] = d;
        for (int k = 1; k < 18; ++k) {
            up[u][k] = up[up[u][k - 1]][k - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; k < 18; ++k) {
            if ((diff >> k) & 1) {
                u = up[u][k];
            }
        }
        if (u == v) return u;
        for (int k = 17; k >= 0; --k) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }

    void fenwick_add(int idx, int val) {
        for (; idx <= n_nodes; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void range_update(int l, int r, int val) {
        fenwick_add(l, val);
        fenwick_add(r + 1, val);
    }

    int point_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n_nodes = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        timer = 0;
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(18, 0));
        dfs(0, 0, 0);

        bit.assign(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            range_update(tin[i], tout[i], mask);
        }

        vector<bool> ans;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                // "update u c"
                int u = 0, idx = 7;
                while (idx < q.size() && q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                char c = q[idx + 1];

                int old_mask = 1 << (s[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int delta = old_mask ^ new_mask;
                s[u] = c;

                range_update(tin[u], tout[u], delta);
            } else {
                // "query u v"
                int u = 0, v = 0, idx = 6;
                while (idx < q.size() && q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                idx++;
                while (idx < q.size()) {
                    v = v * 10 + (q[idx] - '0');
                    idx++;
                }

                int lca = get_lca(u, v);
                int lca_mask = 1 << (s[lca] - 'a');
                int path_mask = point_query(tin[u]) ^ point_query(tin[v]) ^ lca_mask;

                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};