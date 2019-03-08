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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *lead = head;
        ListNode *cur = head, *prev = nullptr;
        
        while (n--) lead = lead->next;
        
        while (lead) {
            lead = lead->next;
            
            prev = cur;
            cur = cur->next;
        }
        
        if (prev) prev->next = cur->next;
        else head = head->next;
        
        cur = nullptr;
        
        return head;
    }
};