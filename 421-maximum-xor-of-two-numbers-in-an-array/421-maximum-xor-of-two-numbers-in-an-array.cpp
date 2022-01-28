class TrieNode{
public:
    TrieNode *left;
    TrieNode *right;
    TrieNode(){
        this->left = NULL; //for 0 bit 
        this->right = NULL; //for 1 bit
    }
};

class Trie{
public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int val) {
        int bitIndex = 30;
        TrieNode *curr = root;
        
        while(bitIndex >= 0) {
            // first we need to know if the bit at bitIndex is 0 or 1
            int mask = 1 << bitIndex;   // creating a mask to find bit val
            int bit = (mask & val) > 0 ? 1 : 0;
            
            if(bit == 1) {
                // if bit is 1, and no right child of root exist
                if(!curr->right) {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }else {
                // if bit is 0, and no right child of root exist
                if(!curr->left) {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
            bitIndex--;
        }
    }
    
    int query(int val) {
        int bitIndex = 30;
        int ans = 0;
        TrieNode *curr = root;
        
        while(bitIndex >= 0) {
            // first we need to know if the bit at bitIndex is 0 or 1
            int mask = 1 << bitIndex;   // creating a mask to find bit val
            int bit = (mask & val) > 0 ? 1 : 0;
            
            if(bit == 1) {
                // if bit is 1, and no right child of root exist
                if(curr->right) {
                    curr = curr->right;
                    ans |= mask;
                } else
                    curr = curr->left;
            }else {
                // if bit is 0, and no right child of root exist
                if(curr->left) 
                    curr = curr->left;
                else {
                    curr = curr->right;
                    ans |= mask;
                }
            }bitIndex--;
        }
        
        return ans;
    }
};

class Solution {
public:
    // brute force
    // tc - o(n2)
    // sc - o(1)
    // should give tle
//     int findMaximumXOR(vector<int>& nums) {
//         int n = nums.size(), mx = INT_MIN;
        
//         for(int i=0; i<n-1; i++) {
//             for(int j = i+1; j<n; j++) {
//                 mx = max(mx, nums[i]^nums[j]);
//             }
//         }
        
//         return mx;
//     }
    // using trie + bit manupulation
    int findMaximumXOR(vector<int>& nums) {
        // for explanation watch this video: https://www.youtube.com/watch?v=OUNfpFswJq8
        
        // step 1: insert all the nums into trie
        Trie *trie = new Trie();
        
        for(int val : nums) {
            trie->insert(val);
        }
        
        // step 2: find max values using bit manupulation and trie search
        int mx = INT_MIN;
        for(int a : nums) {
            int find =  INT_MAX ^ a;
            // returns the nearest max possible value that is present in num
            // when when xored with a gives max possible
            int b = trie->query(find);
            
            mx = max(mx, a^b);
        }
        
        return mx;
    }
};