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

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder , int& postIdx , int is , int ie)
    {
        if (is > ie) return NULL; 

        TreeNode* root = new TreeNode(postorder[postIdx]);
        postIdx--;

        int inIndex;

        for(int i = is ; i <= ie ; i++)
        {
            if(inorder[i] == root->val)
            {
                inIndex = i;
                break;
            }           
        }

        root->right = helper(inorder , postorder , postIdx , inIndex + 1 , ie );
        root->left = helper(inorder, postorder , postIdx ,is, inIndex - 1 );

        return root;
    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postIndex = postorder.size() - 1;

        TreeNode* ans =  helper(inorder, postorder, postIndex, 0 , inorder.size() - 1);

        return ans;
    }
};