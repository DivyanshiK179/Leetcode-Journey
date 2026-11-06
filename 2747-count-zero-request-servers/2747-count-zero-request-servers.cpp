class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) 
        {
            sorted_queries[i] = {queries[i], i};
        }

        sort(sorted_queries.begin(), sorted_queries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> server_count;
        int l = 0, r = 0;
        int total_logs = logs.size();
        
        for (auto& q : sorted_queries) 
        {
            int q_time = q.first;
            int idx = q.second;
            int window_start = q_time - x;
            int window_end = q_time;
            
            while (r < total_logs && logs[r][1] <= window_end) 
            {
                server_count[logs[r][0]]++;
                r++;
            }
            
            while (l < total_logs && logs[l][1] < window_start) 
            {
                server_count[logs[l][0]]--;
                if (server_count[logs[l][0]] == 0) {
                    server_count.erase(logs[l][0]);
                }
                l++;
            }
            
            ans[idx] = n - server_count.size();
        }
        
        return ans;
    }
};