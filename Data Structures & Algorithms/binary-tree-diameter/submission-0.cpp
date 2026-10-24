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
    int ComputeDiameter(TreeNode* root, int &ans) {
        if(root == NULL)
        return 0;

        int currentAns = 0, leftMax= 0 , rightMax = 0;

        if(root->left != NULL) 
            leftMax = 1 + ComputeDiameter(root->left, ans);
        
        if(root->right != NULL) 
            rightMax = 1 + ComputeDiameter(root->right, ans);
        
        ans = max(ans, leftMax + rightMax);

        return max(leftMax, rightMax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        ComputeDiameter(root, ans);

        return ans;
    }
};
