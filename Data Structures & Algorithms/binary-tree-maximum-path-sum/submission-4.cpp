/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int ans;
    int dfs(TreeNode* u){
        int l = u->left ? dfs(u->left) : 0;
        int r = u->right ? dfs(u->right) : 0;
        int v = u->val;

        ans = max({ans, l+v, r+v, v, l+r+v});
        return max({l+v, r+v, v});
    }

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);

        return ans;
    }
};
