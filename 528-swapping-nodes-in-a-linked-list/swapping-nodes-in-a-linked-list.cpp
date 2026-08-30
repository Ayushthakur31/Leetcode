/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i = 0;i < k;i++){
            first = first->next;
        }
        ListNode* firstk = first;
        while(first->next != NULL){
            first = first->next;
            second = second->next;
        }
        int temp = firstk->val;
        firstk->val = second->next->val;
        second->next->val = temp;
        return dummy->next;
    }
};