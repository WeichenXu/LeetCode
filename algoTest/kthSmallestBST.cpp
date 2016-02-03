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
    int kthSmallest(TreeNode* root, int& k) {
        if(!root) return 0;
        int tmp = kthSmallest(root->left, k);
        if(k == 0) return tmp;
        k--;
        if(k == 0) return root->val;
        return kthSmallest(root->right, k);
        
    }
};