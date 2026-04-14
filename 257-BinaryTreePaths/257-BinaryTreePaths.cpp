// Last updated: 15/04/2026, 00:46:44
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
    void dfs(TreeNode* root,vector<string>&ans,int i,string s){
        if(root==NULL) return;
        if(i==0) s+=to_string(root->val);
        else s+="->"+to_string(root->val);
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(s);
            return;
        }
        dfs(root->left,ans,i+1,s);
        dfs(root->right,ans,i+1,s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        vector<string>ans;
        dfs(root,ans,0,"");
        return ans;
    }
};