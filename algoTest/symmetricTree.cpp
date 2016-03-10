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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symetriPair(root->left, root->right);
    }
    bool symetriPair(TreeNode* left, TreeNode* right){
        // left and right contain null
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val) && symetriPair(left->right, right->left) && symetriPair(left->left, right->right);
    }
};