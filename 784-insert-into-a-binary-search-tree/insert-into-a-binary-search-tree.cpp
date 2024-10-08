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
    TreeNode* insert(TreeNode* root,int val){
        if(!root){
            TreeNode* newnode=new TreeNode(val);
            return newnode;
        }
        if(root->val>val)
        root->left=insert(root->left,val);
        else
        if(root->val<val){
            root->right=insert(root->right,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       return insert(root,val);
    }
};