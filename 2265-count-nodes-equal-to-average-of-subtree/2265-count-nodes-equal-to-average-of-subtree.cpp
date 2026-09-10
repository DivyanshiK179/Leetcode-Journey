class Solution {
    int matchingNodes = 0;

    pair<int, int> dfs(TreeNode* node) 
    {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int currentSum = node->val + leftSum + rightSum;
        int currentCount = 1 + leftCount + rightCount;

        if (node->val == currentSum / currentCount) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) 
    {
        matchingNodes = 0;
        dfs(root);
        return matchingNodes;
    }
};