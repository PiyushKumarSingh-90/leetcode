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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int count = 0;

        if(root == NULL) return ans;
        
        while(1)
        {
            int size = q.size();

            if(size == 0) return ans;

            count++;
            vector<int>data;
            
            while(size > 0)
            {
                TreeNode* temp = q.front();
                q.pop();

                data.push_back(temp->val);

                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL)q.push(temp->right);
                size--;
            }

            if(count%2 == 0) reverse(data.begin(), data.end());

            ans.push_back(data);
            
        }
        return ans;
    }
};