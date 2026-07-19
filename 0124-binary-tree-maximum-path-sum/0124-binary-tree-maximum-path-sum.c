/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxSum;

int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    // Ignore negative paths
    if (left < 0)
        left = 0;
    if (right < 0)
        right = 0;

    // Maximum path passing through current node
    int current = left + right + root->val;

    if (current > maxSum)
        maxSum = current;

    // Return maximum gain to parent
    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    maxSum = INT_MIN;
    dfs(root);
    return maxSum;
}