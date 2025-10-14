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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;                       

        queue<pair<TreeNode*, long long>> q;
        q.emplace(root, 0);
        long long ans = 0;

        while (!q.empty()) {
            long long l = q.front().second;
            long long r = q.back().second;
            ans = max(ans, r - l + 1);

            int n = q.size();
            while (n--) {
                auto [curr, idx] = q.front();
                q.pop();

                
                long long normalized = idx - l;

                if (curr->left)  q.emplace(curr->left,  2 * normalized + 1);
                if (curr->right) q.emplace(curr->right, 2 * normalized + 2);
            }
        }

        return (int)ans;
    }
};
