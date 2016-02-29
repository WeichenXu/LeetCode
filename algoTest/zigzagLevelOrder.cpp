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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        inorderTraverse(root, 0);
        for(int i=0; i<res.size(); i++){
            if(i%2){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
    void inorderTraverse(TreeNode* cur, int level){
        if(!cur) return;
        if(level == res.size()){
            vector<int> add;
            res.push_back(add);
        }
        res[level].push_back(cur->val);
        inorderTraverse(cur->left, level+1);
        inorderTraverse(cur->right, level+1);
    }
private:
    vector<vector<int>> res;
};