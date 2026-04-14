// Last updated: 15/04/2026, 00:45:33
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
    void dfs(TreeNode* root, map<int,vector<pair<int,int>>>&mp, int l,int i){
        if(root==NULL) return;
        mp[l-1].push_back({root->val,i});
        dfs(root->left, mp, l-1,i+1);
        dfs(root->right, mp, l+1,i+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        dfs(root,mp,0,0);
        for(auto &[x,it]:mp){
            sort(it.begin(),it.end(),[&](auto &p1,auto &p2){
                if(p1.second==p2.second){
                    return p1.first<p2.first;
                }
                return p1.second<p2.second;
            });
        }
        vector<vector<int>>ans(mp.size());
        int k=0;
        for(auto &[x,it]:mp){
            for(auto&i:it){
                ans[k].push_back(i.first);
            }
            k++;
        }
        return ans;
    }
};