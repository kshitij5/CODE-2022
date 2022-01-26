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
    // will traverse both bst separately and store element into array,
    // compare and return
    
    void bsttraverse(TreeNode* root, vector<int>& res) {
        if(!root) return;
        
        bsttraverse(root->left, res);
        res.push_back(root->val);
        bsttraverse(root->right, res);
        
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> v1, v2, res;
        bsttraverse(root1, v1);
        bsttraverse(root2, v2);
        
        int i = 0, j =0;
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] < v2[j]) {
                res.push_back(v1[i++]);
            }else {
                res.push_back(v2[j++]);
            }
        }
        
        while(i < v1.size()) res.push_back(v1[i++]);
        while(j < v2.size()) res.push_back(v2[j++]);
        return res;
    }
};