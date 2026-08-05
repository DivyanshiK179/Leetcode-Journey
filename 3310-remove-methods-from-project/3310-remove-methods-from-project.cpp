#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> isSuspicious(n, false);
        queue<int> q;
        
        isSuspicious[k] = true;
        q.push(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            
            if (!isSuspicious[u] && isSuspicious[v]) {
                vector<int> allMethods(n);
                iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};