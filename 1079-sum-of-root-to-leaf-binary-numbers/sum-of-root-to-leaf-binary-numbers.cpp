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

    void fun(TreeNode* root,int &ans,string &binary)
    {
        binary += root->val + '0';

        if(!root->left && !root->right)
        {
            ans += stoi(binary, 0, 2);
            binary.pop_back();
            return;
        }

        if(root->left) fun(root->left,ans,binary);
        if(root->right) fun(root->right,ans,binary);
        binary.pop_back();

        return;

    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string binary = "";

        fun(root,ans,binary);

        return ans;
    }
};