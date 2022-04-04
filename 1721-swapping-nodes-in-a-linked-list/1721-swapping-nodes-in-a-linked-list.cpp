/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* tmp = head;
        
        while(tmp) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        int n = v.size(), i = 0;
        swap(v[k-1], v[n-k]);
        
        tmp = head;
        while(tmp) {
            tmp->val = v[i++];
            tmp = tmp->next;
        }
        
        return head;
    }
};