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
    bool isPalindrome(ListNode* head) {
        int n = getSize(head);
        ListNode* l2 = secondHalf(head, n);
        ListNode* l1 = reverse(head, n/2);
        
        return check(l1, l2);
    }
private:
    ListNode* reverse(ListNode* head, int n) {
        ListNode *cur = head, *prev = nullptr;
        
        while (n--) {
            ListNode* aux = cur;
            cur = cur->next;
            aux->next = prev;
            prev = aux;
        }
        
        return prev;
    }
    
    ListNode* secondHalf(ListNode* head, int n) {
        int aux = n/2;
        while (aux) {
            head = head->next;
            aux--;
        }
        
        if (n%2 == 1 and n>1) head = head->next;
        return head;
    }
    
    int getSize(ListNode* head) {
        if (!head) return 0;
        return 1 + getSize(head->next);
    }
    
    bool check(ListNode* l1, ListNode* l2) {
        while (l1 and l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};