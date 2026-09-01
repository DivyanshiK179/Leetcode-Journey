#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int total_litters = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = total_litters++;
                }
            }
        }
        
        if (total_litters == 0) return 0;
        
        int target_mask = (1 << total_litters) - 1;
    
        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << total_litters, -1))
        );
        
        queue<tuple<int, int, int, int, int>> q;
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();
            
            if (e == 0) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int next_e = e - 1;
                int next_mask = mask;
                
                if (classroom[nr][nc] == 'L') {
                    next_mask |= (1 << litter_id[nr][nc]);
                }
                
                if (next_mask == target_mask) {
                    return moves + 1;
                }
                
                if (classroom[nr][nc] == 'R') {
                    next_e = energy;
                }
                
                if (next_e <= max_energy[nr][nc][next_mask]) {
                    continue;
                }
                
                max_energy[nr][nc][next_mask] = next_e;
                q.push({nr, nc, next_mask, next_e, moves + 1});
            }
        }
        
        return -1;
    }
};