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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        while (lists.size() > 1) {
            ListNode* l1 = lists[lists.size()-1]; lists.pop_back();
            ListNode* l2 = lists[lists.size()-1]; lists.pop_back();
            
            l1 = merge(l1, l2);
            lists.push_back(l1);
        }
        
        return lists[0];
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 and !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* ans;
        if (l1->val <= l2->val) {
            ans = l1;
            l1 = l1->next; 
        } else {
            ans = l2;
            l2 = l2->next;
        }
        ans->next = merge(l1, l2);
        return ans;
    }
};