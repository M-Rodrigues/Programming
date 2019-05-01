/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int, ListNode*> pit;
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<pit> pq;
    
    for (ListNode* node : A) {
        if (node != nullptr) {
            pq.push({-node->val, node});
        }
    }
    
    ListNode *head = nullptr, *aux = nullptr;
    
    while(!pq.empty()) {
        ListNode *cur = pq.top().second; 
        pq.pop();
        
        // cout << cur->val << endl;
        if (head == nullptr) {
            head = aux = cur;
        } else {
            aux->next = cur;
            aux = aux->next;
        }
        
        cur = cur->next;
        if (cur != nullptr) {
            pq.push({-cur->val, cur});
        }
    }
    
    return head;
    
}
