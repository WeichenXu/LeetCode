class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head, *last;
        if(cur == NULL) return head;
        int sum = 0, n;
        while(cur!=NULL){
            sum++;
            last = cur;
            cur = cur->next;
        }
        cur = head;
        n = sum-k%sum;
        if(!n) return head;
        while(n>1){
            cur = cur->next;
            n--;
        }
        last->next = head;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};