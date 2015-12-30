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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pointers[k];
        for(int i=0; i<k; i++){
            pointers[i] = head;
            if(!head)   return pointers[0];
            head = head->next;
        }
        
        // reverse
        for(int i=k-1; i>0; i--){
            pointers[i]->next = pointers[i-1];
        }
        pointers[0]->next = reverseKGroup(head, k);
        return pointers[k-1];
    }
};