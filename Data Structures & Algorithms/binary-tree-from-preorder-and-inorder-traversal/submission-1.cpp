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
    unordered_map<int, int> inorderData;
    TreeNode *BuildTheTree(int &index, vector<int>& preorder, int start, int end) {
        int size = preorder.size();

        if(index == size)
        return NULL;

        TreeNode *root = NULL;

        int val = preorder[index];

        if(inorderData.find(val) != inorderData.end() && (inorderData[val]>=start && inorderData[val]<=end)) {
            root = new TreeNode(val);
            index += 1;
            root->left = BuildTheTree(index, preorder, start, inorderData[val]-1);
            root->right = BuildTheTree(index, preorder, inorderData[val]+1, end);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;

        for(int i=0 ; i<inorder.size() ; i++)
        inorderData[inorder[i]] = i;

        return BuildTheTree(index, preorder, 0, inorder.size()-1);
    }
};
