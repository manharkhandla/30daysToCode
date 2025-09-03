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

    void getTarget(TreeNode* original,TreeNode* cloned,TreeNode* target,TreeNode* &ans)
    {
        if(!original) return;
        if(original->val==target->val)
        {
            ans=cloned;
            return;
        }

        getTarget(original->left,cloned->left,target,ans);
        getTarget(original->right,cloned->right,target,ans);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = cloned;
        getTarget(original,cloned,target,ans);
        return ans;
    }
};