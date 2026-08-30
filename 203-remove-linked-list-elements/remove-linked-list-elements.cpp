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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head && head->val == val){
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        ListNode* first = head;
        ListNode* temp = head;
        while(first){
            if(first->val == val){
                temp->next = first->next;
                delete first;
                first = temp->next;
            }
            else{
                temp = first;
                first = first->next;
            }
        }
        return head;
    }
};