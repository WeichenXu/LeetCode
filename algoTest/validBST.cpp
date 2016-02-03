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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return leftNode(root->left, root->val)&&rightNode(root->right, root->val);
    }
    bool leftNode(TreeNode* left, int max){
        if(!left) return true;
        if(left->val >= max) return false;
        if(!leftNode(left->left, left->val)) return false;
        if(!midNode(left->right, left->val, max)) return false;
        return true;
    }
    bool rightNode(TreeNode* right, int min){
        if(!right) return true;
        if(right->val <= min) return false;
        if(!rightNode(right->right, right->val)) return false;
        if(!midNode(right->left, min, right->val)) return false;
        return true;
    }
    bool midNode(TreeNode* mid, int min, int max){
        if(!mid) return true;
        if(mid->val <= min || mid->val >= max) return false;
        if(!midNode(mid->left, min, mid->val)) return false;
        if(!midNode(mid->right, mid->val, max)) return false;
        return true;
    }
};