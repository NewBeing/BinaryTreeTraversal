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
            if(t->right){//右孩子先入栈
                s.push(t->right);
            }
            if(t->left){
                s.push(t->left);
            }
        }
        return result;
    }
};


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode * t = root;
      
        if (t == NULL)
            return result;
        
        while(!s.empty() || t){
            //从根节点开始，每一个节点
            if(t){
                s.push(t);
                t = t->left;//先遍历左子树
            }
            else{//上一节点为叶子或者root
                t = s.top();//
                result.push_back(t->val);  
                s.pop();
                t = t->right;              
            }
        }
        return result;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
/**
 方法1：
 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是
 其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，
 则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右
 孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * t = root;
        TreeNode* pre = NULL;  //记录刚刚访问过的节点
        
        if (t == NULL)
            return result;
        
        s.push(t);
        while(!s.empty()){
            t = s.top();
            if( (t->left == NULL && t->right == NULL) || (pre && (pre == t->left || pre == t->right))){
                result.push_back(t->val);
                pre = t;
            }
            else{
                if(t->right){
                    s.push(t->right);
                }
                if(t->left){
                    s.push(t->left);
                }
            }
        }
        
        return result;
    }
};

/*方法2*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * p = root;
        TreeNode* q;  //记录刚刚访问过的节点
        do{
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            q = NULL;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                if (p->right == q) {  //当右子树已经访问过了，才可以访问根
                    result.push_back(p->val);
                    q = p;  //记录刚刚访问过的节点
                } else {
                    s.push(p); //第一次访问到该节点，需要将它重新入栈
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());
        return result;
    }
};
