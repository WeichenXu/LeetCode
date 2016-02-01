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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        inOrderTraverse(root, 1, res);
        return res;
    }
    void inOrderTraverse(TreeNode* cur, int level, vector<vector<int>>& allOrder){
        if(!cur)    return;
        if(level > allOrder.size()){
            vector<int> tmp;
            allOrder.push_back(tmp);
        }
        allOrder[level-1].push_back(cur->val);
        inOrderTraverse(cur->left, level+1, allOrder);
        inOrderTraverse(cur->right, level+1, allOrder);
    }
};