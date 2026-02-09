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
class Solution 
{
    TreeNode* prev;

    void preorder(TreeNode* curr)
    {
        if(!curr) return;
        
        if(prev)
        {
            prev->left = NULL;
            prev->right = curr;
        }
        
        TreeNode* r = curr->right;
        prev = curr;
        
        preorder(curr->left);
        preorder(r);
    }

    public:

    void flatten(TreeNode* root) 
    {
        prev = NULL;
        preorder(root);
    }

};