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

    int postIndex;  // Track current index in postorder traversal
    unordered_map<int, int> indexMap;  // Store inorder indices for O(1) lookups

    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int is, int ie) 
    {
        if (is > ie) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int inIndex = indexMap[root->val];  // O(1) lookup

        // Build right subtree first (postorder processes right subtree before left)
        root->right = buildTreeUtil(inorder, postorder, inIndex + 1, ie);
        root->left = buildTreeUtil(inorder, postorder, is, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        
        postIndex = postorder.size() - 1; // Start from last element of postorder

        for (int i = 0; i < inorder.size(); i++)
        {
            indexMap[inorder[i]] = i;  // Store inorder indices for quick access
        }

        return buildTreeUtil(inorder, postorder, 0, inorder.size() - 1);
    }
};