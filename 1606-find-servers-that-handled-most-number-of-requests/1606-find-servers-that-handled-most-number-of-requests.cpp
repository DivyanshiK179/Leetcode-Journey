#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        int n = arrival.size();
        std::set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
        std::vector<int> count(k, 0);

        for (int i = 0; i < n; ++i) 
        {
            long long start = arrival[i];
            long long duration = load[i];

            while (!pq.empty() && pq.top().first <= start) 
            {
                available.insert(pq.top().second);
                pq.pop();
            }

            if (available.empty()) 
            {
                continue;
            }

            auto it = available.lower_bound(i % k);
            if (it == available.end()) 
            {
                it = available.begin(); 
            }

            int server_id = *it;
            available.erase(it);

            pq.push({start + duration, server_id});
            count[server_id]++;
        }

        int max_requests = *std::max_element(count.begin(), count.end());
        std::vector<int> result;
        for (int i = 0; i < k; ++i) 
        {
            if (count[i] == max_requests) 
            {
                result.push_back(i);
            }
        }

        return result;
    }
};