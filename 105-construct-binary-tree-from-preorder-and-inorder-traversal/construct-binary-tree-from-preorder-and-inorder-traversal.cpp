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

    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preIdx, int is, int ie)
    {
        if(is > ie) return NULL; // is = inOrder Starting value   &   ie = inorder ending value.
        
        TreeNode* root = new TreeNode(preorder[preIdx]);

        preIdx++;
        
        
        int inIndex;
        
        for(int i = is; i <= ie; i++)
        {
            if(inorder[i] == root->val)
            {
                inIndex = i;
                break;
            }
        }
        
        root->left = helper(preorder, inorder, preIdx, is, inIndex-1);
        root->right = helper(preorder, inorder, preIdx, inIndex+1, ie);
        
        return root;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;

        TreeNode* ans = helper(preorder, inorder, preIndex, 0, inorder.size()-1);
        return ans;
    }   
};