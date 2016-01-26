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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayRangeNode(nums, 0, nums.size()-1);
    }
    TreeNode* arrayRangeNode(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        TreeNode* res = new TreeNode(0);
        if(end == start){
            res->val = nums[start];
            return res;
        }
        if(end - start == 1){
            res->val = nums[end];
            res->left = arrayRangeNode(nums, start, start);
            return res;
        }
        int middle = start + (end-start)/2;
        res->val = nums[middle];
        res->left = arrayRangeNode(nums, start, middle-1);
        res->right = arrayRangeNode(nums, middle+1, end);
        return res;
    }
};