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

class Codec {
public:

    string Serialize(TreeNode* root) {
        if(root == NULL)
        return "N,";

        string ans = to_string(root->val) + ",";

        ans += Serialize(root->left);
        ans += Serialize(root->right);

        return ans;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";

        s =  Serialize(root);
        
        return s;
    }

    TreeNode *Deserialize(vector<string> &nodesDataList, int &i) {
        int size = nodesDataList.size();

        if(nodesDataList[i] == "N")
        {
            i++;
            return NULL;
        }

        TreeNode *root = new TreeNode(stoi(nodesDataList[i]));
        i++;

        root->left = Deserialize(nodesDataList, i);
        root->right = Deserialize(nodesDataList, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodesDataList;
        char separator = ',';

        stringstream ss(data);

        string perNodeData ;

        while(getline(ss, perNodeData, separator)) {
            nodesDataList.push_back(perNodeData);
        }

        int i=0;
        return Deserialize(nodesDataList, i);

    }
};
