class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* headSwap = head->next;
        head->next = swapPairs(headSwap->next);
        headSwap->next = head;
        return headSwap;
    }
};