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
    void InorderTraversal(TreeNode *root, vector<int> &ans) {
        if(root == NULL)
        return ;

        InorderTraversal(root->left, ans);
        ans.push_back(root->val);
        InorderTraversal(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;

        InorderTraversal(root, ans);

        if(k <= ans.size())
        return ans[k-1];
        return -1;
    }
};
