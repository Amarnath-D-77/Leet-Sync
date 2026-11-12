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
    vector<TreeNode*>gen(int start,int end){
       vector<TreeNode*>all;
       if(start>end){
        all.push_back(NULL);
        return all;
       }
       for(int i=start;i<=end;i++){
        vector<TreeNode*>left=gen(start,i-1);
        vector<TreeNode*>right=gen(i+1,end);
        for(TreeNode*l:left){
            for(TreeNode*r:right){
                TreeNode*cur=new TreeNode(i);
                cur->left=l;
                cur->right=r;
                all.push_back(cur);
            }
        }
       }
       return all;
    }
    vector<TreeNode*>generateTrees(int n){
        if(n==0){
            return {NULL};
        }
        return gen(1,n);
    }
};