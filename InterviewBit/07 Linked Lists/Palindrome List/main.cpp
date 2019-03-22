/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if (A == nullptr) return 1;
    
    ListNode *fast, *slow, *prev, *aux;
    
    prev == nullptr;
    fast = slow = A;
    
    while (fast != nullptr and fast->next != nullptr) {
        fast = fast->next->next;
        
        /* reversing the first half */
        aux = slow;
        slow = slow->next;
        aux->next = prev;
        prev = aux;
    }
    
    /* check if list has even size */
    if (fast != nullptr) aux = slow->next;
    else aux = slow->next;
    
    
    while (aux != nullptr and prev != nullptr) {
        if (aux->val != prev->val) return 0;
        
        aux = aux->next;
        prev = prev->next;
    }
    return 1;
}
