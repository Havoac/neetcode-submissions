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
    TreeNode *BuildTheTree(int &index, vector<int>& preorder, int start, int end, vector<int>& inorder) {
        int size = preorder.size();

        if(index == size)
        return NULL;

        TreeNode *root = NULL;

        for(int i=start ; i<=end ; i++) {
            if(inorder[i] == preorder[index]) {
                root = new TreeNode(preorder[index]);
                index += 1;
                root->left = BuildTheTree(index, preorder, start, i-1, inorder);
                root->right = BuildTheTree(index, preorder, i+1, end, inorder);
                break;
            }
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return BuildTheTree(index, preorder, 0, inorder.size()-1, inorder);
    }
};
