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
    int fun(TreeNode* root,int &ans){
        if(!root)
        return 0;
        int l=fun(root->left,ans);
        int r=fun(root->right,ans);
        int temp=1+max(l,r);
        // temp=max(temp,1+l+r);
        ans=max(ans,max(temp,1+l+r));
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        fun(root,ans);
        return ans-1;
    }
};