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
        ListNode *left, *right;
        ListNode *root = NULL, *cur;
        vector<ListNode*> leftLists, rightLists;
        vector<ListNode*> toMerge;
        switch (lists.size()){
            case 0: return NULL; break;
            case 1: return lists[0]; break;
            case 2: 
                left = lists[0];
                right = lists[1];
                if(!left)   return right;
                if(!right)  return left;
                if(left->val < right->val){
                    root = left;
                    left = left->next;
                }
                else{
                    root = right;
                    right = right->next;
                }
                cur = root;
                while(left && right){
                    if(left->val < right->val){
                        cur->next = left;
                        left = left->next;
                    }
                    else{
                        cur->next = right;
                        right = right->next;
                    }
                    cur = cur->next;
                }
                if(right) cur->next = right;
                else cur->next = left;
                return root;
                break;
            default:
                leftLists = vector<ListNode*>(lists.begin(), lists.begin()+lists.size()/2);
                rightLists = vector<ListNode*>(lists.begin()+lists.size()/2, lists.end());
                left =  mergeKLists(leftLists);
                right = mergeKLists(rightLists);
                toMerge.push_back(left); toMerge.push_back(right);
                return mergeKLists(toMerge);
                break;
        }
    }
};