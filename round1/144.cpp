//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != nullptr){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }


private: 
    vector<int> ans;
};



//普通迭代版
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(root == nullptr)
            return ans;
        TreeNode* cur = root;
        while(!stk.empty() ||  cur != nullptr){
            while(cur != nullptr){
                ans.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return ans;
    }
};



//Morris 遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(root == nullptr)
            return ans;
        TreeNode* p1 = root, *p2 = nullptr;
        while(p1 != nullptr){
            p2 = p1->left;
            if(p2 != nullptr){
                while(p2->right != nullptr && p2->right != p1){
                    p2 = p2->right;
                }
                if(p2 ->right == nullptr){
                    ans.push_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }else{
                    p2 -> right = nullptr;
                }
            }else{
                ans.push_back(p1->val);
            }
            p1 = p1->right;
        }
        return ans;
    }
};