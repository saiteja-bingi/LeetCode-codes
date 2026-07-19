// Last updated: 19/7/2026, 8:27:52 am
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int c=0;
15    int find(TreeNode* root){
16        if(root==NULL) return 0;
17        if(root->left==NULL&&root->right){
18            c++;
19            return root->val;
20        }
21        int a=find(root->left);
22        int b=find(root->right);
23        if(max({a,b,root->val})==root->val) c++;
24        return max({a,b,root->val});
25    }
26    int countDominantNodes(TreeNode* root) {
27        int a=find(root);
28        return c;
29    }
30};