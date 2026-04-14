// Last updated: 15/04/2026, 00:46:50
/**
 * Definition for a binary tree root.
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
    int lefth(TreeNode* root){
        if(!root) return 0;
        return 1+lefth(root->left);
    }
    int righth(TreeNode* root){
        if(!root) return 0;
        return 1+righth(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=lefth(root->left);
        int rh=righth(root->right);
        if(lh==rh) return (1<<(lh+1))-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};