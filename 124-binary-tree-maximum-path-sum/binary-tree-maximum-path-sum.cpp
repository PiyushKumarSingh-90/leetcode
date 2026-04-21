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

    int maxSum;
    
    int solve(TreeNode* root) 
    {
        if(root == NULL) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int path_through_root = left + right + root->val; //(1)
        
        int one_side_path = max(left, right) + root->val; //(2)
        
        int only_root = root->val; //(3)
        
        maxSum = max({maxSum, path_through_root, one_side_path, only_root});
            
        // most important part
        return max(one_side_path, only_root);   
    }

    int maxPathSum(TreeNode* root) 
    {
        maxSum = INT_MIN;
        
        solve(root);
        
        return maxSum;
    }
};