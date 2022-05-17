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
    // bfs
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
//         queue<TreeNode*> q;
//         q.push(cloned);
        
//         while(!q.empty()) {
//             int size = q.size();
            
//             for(int i=0; i<size; i++) {
//                 TreeNode* temp = q.front();
//                 q.pop();
                
//                 if(temp->val == target->val) return temp;
                
//                 if(temp->left != NULL) q.push(temp->left);
//                 if(temp->right != NULL) q.push(temp->right);
//             }
//         }
        
//         return NULL;
//     }
    
    //  dfs
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned) return NULL;
        
        if(target->val == cloned->val) {
            return cloned;
        }
        
        TreeNode* left = getTargetCopy(original, cloned->left, target);
        if(left!=NULL) {
            return left;
        }
        TreeNode* right = getTargetCopy(original, cloned->right, target);
        if(right!=NULL) {
            return right;
        }
        return NULL;
    }
};