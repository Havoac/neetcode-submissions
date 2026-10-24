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
    int ComputeHeightAndCheck(TreeNode *root, bool &ans) {
        if(root == NULL)
        return 0;

        if(!ans)
        return 0;

        int leftHeight = 1 + ComputeHeightAndCheck(root->left, ans);
        int rightHeight = 1 + ComputeHeightAndCheck(root->right, ans);

        if(abs(rightHeight-leftHeight) > 1) {
            ans = false;
            return 0;
        }

        return max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;

        ComputeHeightAndCheck(root, ans);

        return ans;
    }
};
