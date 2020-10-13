//no efficient
#include<cstdio>
#include<vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

 // 中序遍历
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
// 后序遍历
void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

TreeNode* buildTreeByIdx(vector<int> inorder, vector<int> postorder, int inorderL, int inorderR, int postorderL, int postorderR){
    if(inorderL > inorderR ) return NULL;
    int rootVal = postorder[postorderR];
    TreeNode * root = new TreeNode(rootVal);
    int idx;
    //can be optimized by hash map
    for(int i = inorderL; i <= inorderR; i++){
        if(inorder[i] == rootVal){
            idx = i;
            break;
        }
    }
    //attention here
    root->left = buildTreeByIdx(inorder, postorder, inorderL, idx-1, postorderL, postorderL+idx-inorderL-1);
    root->right = buildTreeByIdx(inorder, postorder, idx+1, inorderR, idx+postorderR-inorderR, postorderR-1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    TreeNode* root = buildTreeByIdx(inorder, postorder , 0, n-1, 0, n-1);
    return root;
}

int main(){
    vector<int> v1{9,3,15,20,7};
    vector<int> v2{9,15,7,20,3};
    TreeNode* root = buildTree(v1, v2);
    postorder(root);
    inorder(root);
    return 0;  
}

/*

class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据 root 所在位置分成左右两棵子树
        int index = idx_map[root_val];

        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立（元素，下标）键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};
*/