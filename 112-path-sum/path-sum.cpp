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

    bool hasSum(TreeNode* root,int targetSum,int &sum)
    {
        sum+=root->val;
        if((!root->left && !root->right) && sum!=targetSum)
        {
            sum-=root->val;
            return false;
        } 
        if((!root->left && !root->right) && sum==targetSum) return true;

        bool leftAns = false;
        if(root->left)
        {
            leftAns = hasSum(root->left,targetSum,sum);
        }
        bool rightAns = false;
        if(root->right)
        {
            rightAns = hasSum(root->right,targetSum,sum);
        }
        sum-=root->val;
        return leftAns || rightAns;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=0;
        return hasSum(root,targetSum,sum);
    }
};