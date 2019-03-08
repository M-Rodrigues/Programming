/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


// Iteratively  
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode rev = null;
        while (head != null) {
            ListNode aux = head;
            head = head.next;
            
            aux.next = rev;
            rev = aux;
        }
        
        return rev;        
    }
}

// Recursively
class Solution {
    public ListNode reverseList(ListNode head) {
        return reverseList(head, null); 
    }
    
    private ListNode reverseList(ListNode head, ListNode ans) {
        if (head == null) return ans;
        
        ListNode aux = head;
        head = head.next;
        
        aux.next = ans;
        ans = aux;
        
        return reverseList(head, ans);
    }
}