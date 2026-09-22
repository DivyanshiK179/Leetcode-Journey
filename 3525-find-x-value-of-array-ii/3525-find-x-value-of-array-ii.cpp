#include <vector>
#include <array>

using namespace std;

class Solution {
    struct Node {
        int prod;
        array<int, 5> cnt;
        Node() : prod(1), cnt{0, 0, 0, 0, 0} {}
    };

    int n, K;
    vector<Node> tree;

    void merge(Node& res, const Node& left, const Node& right) {
        res.prod = (left.prod * right.prod) % K;

        for (int r = 0; r < K; ++r) {
            res.cnt[r] = left.cnt[r];
        }

        for (int r = 0; r < K; ++r) {
            if (right.cnt[r] > 0) {
                int combined_rem = (left.prod * r) % K;
                res.cnt[combined_rem] += right.cnt[r];
            }
        }
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            tree[node] = Node();
            int rem = nums[l] % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node();
            int rem = val % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    void query(int node, int l, int r, int ql, int qr, Node& acc) {
        if (ql <= l && r <= qr) {
            if (acc.prod == -1) {
                acc = tree[node];
            } else {
                Node temp;
                merge(temp, acc, tree[node]);
                acc = temp;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            query(2 * node, l, mid, ql, qr, acc);
        }
        if (qr > mid) {
            query(2 * node + 1, mid + 1, r, ql, qr, acc);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        n = nums.size();
        K = k;
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);

            Node acc;
            acc.prod = -1; 
            query(1, 0, n - 1, start, n - 1, acc);
            ans.push_back(acc.cnt[x]);
        }

        return ans;
    }
};