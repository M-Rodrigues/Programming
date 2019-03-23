/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* split(ListNode *head) {
    ListNode *slow = head, *fast = head;
    
    while ( fast != nullptr 
            and fast->next != nullptr 
            and fast->next->next != nullptr
    ) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    ListNode *l = slow->next;
    slow->next = nullptr;
    
    return l;
}
 
ListNode* reverse(ListNode *head) {
    if (head == nullptr or head->next == nullptr) return head;
    
    ListNode *prev = nullptr, *cur = head;
    
    while (cur != nullptr) {
        ListNode *aux = head;
        aux = head;
        head = head->next;
        
        aux->next = prev;
        prev = aux;
    }
    
    return prev;
}
 
void update(ListNode* l1, ListNode *l2) {
    while (l2 != nullptr) {
        l1->val = l2->val - l1->val;
        l1 = l1->next;
        l2 = l2->next;
    }
}
 
ListNode* unite(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) return l2;
    
    ListNode *aux = l1;
    while (aux->next != nullptr) aux = aux->next;
    
    aux->next = l2;
    
    return l1;
}

ListNode* Solution::subtract(ListNode* A) {
    if (A == nullptr or A->next == nullptr) return A;
    
    // Split the LL in two parts
    ListNode *second = split(A);
    
    // Reverse the second part
    second = reverse(second);
    
    // Update the first half
    update(A,second);
    
    // Reverse de second back
    second = reverse(second);
    
    // Unite both
    A = unite(A,second);
    
    return A;
}
