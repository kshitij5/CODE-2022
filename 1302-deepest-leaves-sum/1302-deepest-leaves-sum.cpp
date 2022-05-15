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
    // dfs
//     int deepestLeavesSum(TreeNode* root) {
//         int sum = 0;
//         vector<int> l;
//         queue<TreeNode*> q;
//         q.push(root);
//         l.push_back(root->val);
        
//         while(!q.empty()) {
//             int size = q.size();
            
//             vector<int> res;
//             for(int i=0; i<size; i++) {
//                 TreeNode* st = q.front();
//                 q.pop();
                
//                 if(st->left!=NULL) {
//                     q.push(st->left);
//                     res.push_back(st->left->val);
//                 }
//                 if(st->right!=NULL) {
//                     q.push(st->right);
//                     res.push_back(st->right->val);
//                 }
//             }
            
//             if(!q.empty()) {
//                 l = res;        
//             }
//         }
        
//         for(int i: l)sum+=i;
        
//         return sum;
//     }
    // space efficient bfs
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, n;
        queue<TreeNode*> q; // required for level-order traversal
        q.push(root);
        while(!q.empty()){
            sum = 0, n = size(q); // reset sum when deeper level is reached and accumulate for that level
            for(int i = 0; i < n; i++){
                auto top = q.front(); q.pop();
                sum += top -> val;     
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
            }                
        }
        return sum; // final value held by 'sum' will be sum of values of nodes at the deepest level
    }
};