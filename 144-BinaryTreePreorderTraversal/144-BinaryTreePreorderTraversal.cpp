// Last updated: 10/27/2025, 7:09:10 PM
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
        vector<int>arr;
        if(root==NULL) return arr;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            arr.emplace_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return arr;

    }
};