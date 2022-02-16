/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
        {
            return head;
        }
        ListNode p1 = head;
        ListNode p2 = head.next;
        while(p2!=null)
        {
            int temp = 0;
            temp = p1.val;
            p1.val = p2.val;
            p2.val = temp;
            
            if(p2.next == null)
            {
                break;
            }
            else
            {
                p1 = p1.next.next;
                p2 = p2.next.next;
            }
        }
        return head;
    }
}