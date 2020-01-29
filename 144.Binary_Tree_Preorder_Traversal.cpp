/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        vector<int> tmp_child;

        if (root == NULL)
            return output;
        else
            output.push_back(root->val);
        
        if( root->left != NULL)
        {
            tmp_child = preorderTraversal(root->left);
            
            for (unsigned int i=0; i < tmp_child.size(); ++i)
                 output.push_back(tmp_child.at(i));
        }
        
        tmp_child.clear();
        
        if( root->right != NULL)
        {
            tmp_child = preorderTraversal(root->right);
                        
            for (unsigned int i=0; i < tmp_child.size(); ++i)
                 output.push_back(tmp_child.at(i));
        }
           
        return output;
    }
};
