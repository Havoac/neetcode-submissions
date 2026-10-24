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
public:
    void Traverse(TreeNode* root, int &ans, int val) {
        if(root == NULL)
        return ;

        if(root->val >= val)
        ans += 1;

        val = max(val, root->val);

        Traverse(root->left, ans, val);
        Traverse(root->right, ans, val);
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL)
        return 0;

        int ans = 0;

        Traverse(root, ans, root->val);

        return ans;
    }
};
