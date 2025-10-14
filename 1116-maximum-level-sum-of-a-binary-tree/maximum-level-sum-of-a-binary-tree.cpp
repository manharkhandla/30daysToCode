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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ansLevel = 0;

        queue<TreeNode*> q;
        q.push(root);

        int currentLevel = 1;

        while(!q.empty())
        {
            int n = q.size();
            int currentSum = 0;

            while(n--)
            {
                TreeNode* temp = q.front();
                currentSum+=temp->val;
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(currentSum>maxSum)
            {
                maxSum = currentSum;
                ansLevel = currentLevel;
            }

            currentLevel++;
        }

        return ansLevel;

    }
};