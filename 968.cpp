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
    struct state{
        int withCam;
        int noCamWatchByDad;
        int noCamWatchedBySon;
        state(int a, int b, int c): withCam(a), noCamWatchByDad(b), noCamWatchedBySon(c){}; 
    };

    state minCam(TreeNode* root){
        if(root == NULL){
            state tmp = state(100, 0, 0);
            return tmp;
        }

        state left = minCam(root->left);
        state right = minCam(root->right);

        int withCam = 1 + min({
            left.noCamWatchByDad + right.noCamWatchByDad,
            left.withCam + right.noCamWatchByDad,
            left.noCamWatchByDad + right.withCam
        });

        int noCamWatchByDad = min({
            left.withCam + right.withCam,
            left.withCam + right.noCamWatchedBySon,
            left.noCamWatchedBySon + right.withCam,
            left.noCamWatchedBySon + right.noCamWatchedBySon
        });

        int noCamWatchedBySon = min({
            left.withCam + right.withCam,
            left.withCam + right.noCamWatchedBySon,
            left.noCamWatchedBySon + right.withCam
        });

        state tmp = state(withCam, noCamWatchByDad, noCamWatchedBySon);
        return tmp;
    }
    int minCameraCover(TreeNode* root) {
        state res = minCam(root);
        return min(res.withCam, res.noCamWatchedBySon); // root有相机，root没有相机，被儿子监控
    }
};