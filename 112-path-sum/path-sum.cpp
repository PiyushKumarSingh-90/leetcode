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
public:

    bool b=0;
    
    void preorder(int s,int targetSum,TreeNode* root)
    {
        
        if(!root)return;
        
        s +=(root->val);
        
        if(!root->left && !root->right)
        {
            if(s==targetSum)
            {
                b=1;
            }
        }
        
        preorder(s,targetSum,root->left);
        preorder(s,targetSum,root->right);
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int s=0;

        preorder(s,targetSum,root);
        
        return b;
    }
};