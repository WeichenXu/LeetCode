/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        // push the left candidates on stack
        iterateNode(root);
    }
    void iterateNode(TreeNode *cur){
        while(cur){
            minStack.push(cur);
            cur = cur->left;
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !minStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = minStack.top();
        minStack.pop();
        iterateNode(top->right);
        return top->val;
    }
    stack<TreeNode*> minStack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */