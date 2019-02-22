/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow;
        ListNode* fast; 
        slow = fast = head;
        
        do {
            if (slow) slow = slow->next;
            
            if (fast) fast = fast->next;
            if (fast) fast = fast->next;
            
            if (!slow || !fast) return false;
        } while (slow != fast);
        return true;
    }
};