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
    const int MIN_LIMIT = -1000000001;
    const int MAX_LIMIT = 1000000001;

    bool CheckValidity(TreeNode* root, int min, int max) {
        if(root == NULL)
        return true;

        if(root->val <= min || root->val >= max)
        return false;

        if(!CheckValidity(root->left, min, root->val))
        return false;

        if(!CheckValidity(root->right, root->val, max))
        return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return (CheckValidity(root->left, MIN_LIMIT, root->val) && CheckValidity(root->right, root->val, MAX_LIMIT));
    }
};
