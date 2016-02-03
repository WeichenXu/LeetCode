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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        if(!a || !b) return NULL;
        bool aTurned = false, bTurned = false;
        while(1){
            if(a == b) return a;
            if(a){
                a = a->next;
            }
            else{
                if(aTurned) return NULL;
                else{
                    a = headB;
                    aTurned = true;
                }
            }
            if(b){
                b = b->next;
            }
            else{
                if(bTurned) return NULL;
                else{
                    b = headA;
                    bTurned = true;
                }
            }
        }
    }
};