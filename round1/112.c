/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    sum=sum-root->val;
    if(sum==0&&!root->left&&!root->right)
        return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);

}