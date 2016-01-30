/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        preOrder(root, res);
        //res[res.length()-1] = '';
        //cout<<res;
        return res;
    }
    void preOrder(TreeNode* cur, string &str){
        if(cur != NULL){
            str += to_string(cur->val);
            str.append(1, ',');
        }
        else{
            str += "null,";
            return;
        }
        preOrder(cur->left, str);
        preOrder(cur->right, str);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int tmp = 0;
        return getNode(data, tmp);
        //return NULL;
    }
    TreeNode* getNode(string& data, int& cur){
        string sub = getStrsepI(data, cur);
        if(!sub.compare("null")){
            return NULL;
        }
        TreeNode *res = new TreeNode(atoi(sub.c_str()));
        //res->val = atoi(sub);
        res->left = getNode(data, cur);
        res->right = getNode(data, cur);
        return res;
        
    }
    string getStrsepI(string& data, int& cur){
        int pre = cur+1;
        cur = data.find(',', pre);
        return data.substr(pre, cur-pre);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));