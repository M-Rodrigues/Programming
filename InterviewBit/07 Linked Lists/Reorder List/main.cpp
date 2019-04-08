/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A) {
    ListNode *prev = nullptr, *aux;
    
    while (A != nullptr) {
        aux = prev;
        prev = A;
        A = A->next;
        prev->next = aux;
    }
    
    return prev;
}

ListNode* split(ListNode *A) {
    ListNode *prev, *slow, *fast;
    
    prev = nullptr;
    slow = fast = A;
    
    while (fast != nullptr and fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    if (prev != nullptr) {
        prev->next = nullptr;
        return slow;
    } else {
        return nullptr;
    }
}

ListNode* merge(ListNode *A, ListNode *B) {
    ListNode* head = A, *A1, *B1, *prev;
    
    while (A != nullptr and B != nullptr) {
        
        A1 = A->next;
        A->next = B;
        A = A1;

        if (A != nullptr) {
            B1 = B->next;
            B->next = A;
            B = B1;
        }     
    }

    return head;
} 
 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* B = split(A);
    
    B = reverse(B);
    
    A = merge(A,B);

    return A;
}
