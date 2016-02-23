/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUStree(root, count);
        return count;
    }
    bool isUStree(TreeNode* cur, int &count){
        // return true when node is null
        if(!cur) return true;
        // recursively check the chilren
        bool res = true;
        if(!isUStree(cur->left, count)) res = false;
        if(!isUStree(cur->right, count)) res = false;
        if(res){
            if((!(cur->left) || (cur->left->val == cur->val)) && (!(cur->right) || (cur->right->val == cur->val))){
                   count++;
                   //cout<<cur->val<<endl;
                   return true;
            }
        }
        return false;
    }
};