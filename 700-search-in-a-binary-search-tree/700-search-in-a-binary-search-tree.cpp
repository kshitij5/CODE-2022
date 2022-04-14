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
    // brute force
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(!root || root->val == val) return root;
        
//         TreeNode* left = searchBST(root->left, val);
//         TreeNode* right = searchBST(root->right, val);
        
//         if(left!=nullptr) return left;
//         if(right!=nullptr) return right;
//         return nullptr;
//     }
    
    // using property of bst
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        if(root->val<val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
    }
};