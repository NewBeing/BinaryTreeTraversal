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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;//非递归方式，用栈模拟实现
        TreeNode * t;
        
        if(root == NULL){
            return result;
        }
        s.push(root);//根节点入栈
        
        while(!s.empty()) {
            t = s.top();
            s.pop();
            result.push_back(t->val);
            if(t->right){
                s.push(t->right);
            }
            if(t->left){
                s.push(t->left);
            }
        }
        return result;
    }
};
