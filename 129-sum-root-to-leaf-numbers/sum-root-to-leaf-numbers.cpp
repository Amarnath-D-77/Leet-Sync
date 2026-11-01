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
    void dfs(TreeNode*root,string cur,int &tot){
        if(root==NULL){
            return;
        }
        cur+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
          tot+=stoi(cur);
          return;
        }
        dfs(root->left,cur,tot);
        dfs(root->right,cur,tot);
    }
    int sumNumbers(TreeNode*root){
        int tot=0;
        string cur="";
        dfs(root,cur,tot);
        return tot;
    }
};