/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// 4 ms, 98.81%
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        
        ListNode odd = head;
        ListNode even = head.next;
        ListNode l = even;
        
        while (odd != null || even != null) {
            if (even != null) odd.next = even.next;
            if (odd != null) odd = odd.next;
            
            if (odd != null) even.next = odd.next;
            if (even != null) even = even.next;
        }
        
        ListNode aux = head;
        while (aux.next != null) { aux = aux.next; }
        aux.next = l;
        
        return head;
    }
}