//二叉树的最大深度
//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

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
    int DFS(TreeNode* root,int val){
        if(root!=NULL){
            val++;
            return max(DFS(root->left,val),DFS(root->right,val));
        }
        return val;
    }

    int maxDepth(TreeNode* root) {
        int ans=DFS(root,0);
        return ans;
    }
};