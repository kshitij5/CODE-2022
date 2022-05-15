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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        vector<int> l;
        queue<TreeNode*> q;
        q.push(root);
        l.push_back(root->val);
        
        while(!q.empty()) {
            int size = q.size();
            
            vector<int> res;
            for(int i=0; i<size; i++) {
                TreeNode* st = q.front();
                q.pop();
                
                if(st->left!=NULL) {
                    q.push(st->left);
                    res.push_back(st->left->val);
                }
                if(st->right!=NULL) {
                    q.push(st->right);
                    res.push_back(st->right->val);
                }
            }
            
            if(!q.empty()) {
                l = res;        
            }
        }
        
        for(int i: l)sum+=i;
        
        return sum;
    }
};