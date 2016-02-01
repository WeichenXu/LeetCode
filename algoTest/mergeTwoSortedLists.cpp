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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *next = NULL, *cur = NULL;
        if(l1 && l2)    head = l1->val<l2->val ? l1:l2;
        else{
            if(!l1) return l2;
            if(!l2) return l1;
        }
        cur = head;
        while(l1&&l2){
            if(l1->val < l2->val){
                next = l1;
                l1 = l1->next;
            }
            else{
                next = l2;
                l2 = l2->next;
            }
            cur->next = next;
            cur = next;
        }
        if(l1) cur->next = l1;
        else cur->next = l2;
        return head;
    }
};