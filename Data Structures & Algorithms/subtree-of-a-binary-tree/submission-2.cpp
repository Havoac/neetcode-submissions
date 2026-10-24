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
    bool IsASubTree(TreeNode *root1, TreeNode *root2) {
        if(root1==NULL && root2==NULL)
        return true;

        if(root1==NULL || root2==NULL)
        return false;

        if(root1->val != root2->val)
        return false;

        if(IsASubTree(root1->left, root2->left) && IsASubTree(root1->right, root2->right))
        return true;

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==root)
        return true;

        if(root==NULL || subRoot==root)
        return false;

        if(IsASubTree(root, subRoot))
        return true;

        if(isSubtree(root->left, subRoot))
        return true;

        if(isSubtree(root->right, subRoot))
        return true;

        return false;
    }
};
