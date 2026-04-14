// Last updated: 15/04/2026, 00:45:41
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=root;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
        int dist=0;
        while(!q.empty()) {
            q.pop();
        }
        unordered_map<TreeNode*,int>vis;
        q.push(target);
        vis[target]=1;
        while(dist<k&&!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&vis[node->left]!=1){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right&&vis[node->right]!=1){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(vis[parent[node]]!=1){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
            dist++;
        }
        vector<int>ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};