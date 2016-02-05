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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(1){
            if(!slow) return false;
            else slow = slow->next;
            if(!fast) return false;
            fast = fast->next;
            if(!fast) return false;
            fast = fast->next;
            if(slow == fast) return true;
        }
    }
};