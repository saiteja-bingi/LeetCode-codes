// Last updated: 15/04/2026, 00:45:53
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        long long ans=0;
        while(!q.empty()){
            long long sz=q.size();
            long long st=q.front().second;
            long long en;
            for(long long j=0;j<sz;j++){
                auto[node,i]=q.front();
                en=i;
                i-=st;
                if(node->left) q.push({node->left,2*i});
                if(node->right) q.push({node->right,2*i+1});
                q.pop();
            }
            ans=max(ans,en-st+1);
        }
        return (int)ans;
    }
};