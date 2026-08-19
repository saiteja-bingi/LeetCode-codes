// Last updated: 19/8/2026, 11:57:53 pm
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
    int c=0;
    int find(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right){
            c++;
            return root->val;
        }
        int a=find(root->left);
        int b=find(root->right);
        if(max({a,b,root->val})==root->val) c++;
        return max({a,b,root->val});
    }
    int countDominantNodes(TreeNode* root) {
        int a=find(root);
        return c;
    }
};