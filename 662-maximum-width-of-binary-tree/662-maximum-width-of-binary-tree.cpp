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
    // using bfs
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long res = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            long long mn = q.front().second;
            long long first, last;
            
            for (int i = 0, n = q.size(); i < n; i++) {
                long long curr_id = q.front().second - mn;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0) first = curr_id;
                if(i == n-1) last = curr_id;
                
                if (node->left) 
                    q.push({node->left, curr_id * 2});
                if (node->right) 
                    q.push({node->right, curr_id * 2 + 1});
            }
            res = max(res, last - first + 1);
        }
        return res;
    }
};