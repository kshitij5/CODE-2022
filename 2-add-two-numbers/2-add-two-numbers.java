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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int carry = 0;
        ListNode reversedSum = null;
        ListNode start = null;
        ListNode temp = null;
        
        while(l1!=null || l2!=null){
            sum = (l1!=null?l1.val:0) + (l2!=null?l2.val:0) + carry;
            
            if(sum >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            sum = sum%10;
            
            temp = new ListNode(sum);
            
            if(start == null){
                start =  temp;
            }else{
                reversedSum.next = temp;
            }
            reversedSum = temp;
            if (carry > 0) {
                temp.next = new ListNode(carry);
            }
            
            if(l1!=null)
                l1 = l1.next;
            
            if(l2!=null)
                l2 = l2.next;
        }
        return start;
    }
}