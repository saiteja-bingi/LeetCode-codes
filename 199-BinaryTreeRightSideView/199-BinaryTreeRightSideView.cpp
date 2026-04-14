// Last updated: 15/04/2026, 00:46:57
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        map<int,int>mp;
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            TreeNode* node=x.first;
            int h=x.second;
            if(!mp.count(h)) mp[h]=node->val;
            if(node->right) q.push({node->right,h+1});
            if(node->left) q.push({node->left,h+1});
        }
        for(auto&[x,y]:mp){
            ans.push_back(y);
        }
        return ans;
    }
};