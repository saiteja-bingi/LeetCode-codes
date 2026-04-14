// Last updated: 15/04/2026, 00:44:45
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
    TreeNode* dfs(TreeNode* root,int start){
        if(!root) return NULL; 
        if(root->val==start) return root;
        TreeNode* l=dfs(root->left,start);
        TreeNode* r=dfs(root->right,start);
        if(!l) return r;
        return l;
    }
    int amountOfTime(TreeNode* root, int start) {
        // find node
        TreeNode* target=dfs(root,start);
        // for parents
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
        unordered_map<TreeNode*,bool>vis;
        while(!q.empty()) q.pop();
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            dist++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&!vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right&&!vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(!vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        }
        return dist-1;
    }
};