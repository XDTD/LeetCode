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
    void inOrder(TreeNode* root, int& pre, int &ans){
        if(root == NULL)
            return;
        inOrder(root->left, pre, ans);
        if(pre == -1){
            pre = root->val;
        }else{
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        inOrder(root->right, pre, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        inOrder(root, pre, ans);
        return ans;
    }
};