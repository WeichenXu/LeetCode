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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        return findLC(root, 0, root->val);
    }
    int findLC(TreeNode* root, int curLen, int val){
        if(root == NULL)    return curLen;
        int nextLen = root->val == (val+1)?++curLen:1;
        //cout<<nextLen<<" "<<root->val<<endl;
        return max(max(nextLen, findLC(root->left, nextLen, root->val)), findLC(root->right, nextLen, root->val));
    }
};