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
    int leftheight(TreeNode* root){
        int ans=0;
        while(root){
            root=root->left;
            ans++;
        }
        return ans;
    }
    int rightheight(TreeNode* root){
        int ans=0;
        while(root){
          root=root->right;
            ans++;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh)
        return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};