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
    int closestValue(TreeNode* root, double target) {
        if(target > root->val){
            if(!root->right) return root->val;
            double rightC = closestValue(root->right, target);
            return abs(root->val-target)<abs(rightC-target)?(root->val):rightC;
        }
        else{
            if(!root->left) return root->val;
            double leftC = closestValue(root->left, target);
            return abs(root->val-target)<abs(leftC-target)?(root->val):leftC;
        }
    }
};