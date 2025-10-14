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

    int find(vector<int>& inorder,int target,int inst,int inend)
    {
        for(int i=inst;i<=inend;i++)
        {
            if(inorder[i]==target) return i;
        }

        return -1;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inst,int inend,int idx)
    {
        if(inst > inend) return NULL;

        TreeNode* root = new TreeNode(postorder[idx]);

        int i = find(inorder,postorder[idx],inst,inend);

        root->left = solve(inorder,postorder,inst,i-1,idx-(inend-i)-1);
        root->right = solve(inorder,postorder,i+1,inend,idx-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int inst = 0;
        int inend = n-1;

        return  solve(inorder,postorder,inst,inend,inend);
    }
};