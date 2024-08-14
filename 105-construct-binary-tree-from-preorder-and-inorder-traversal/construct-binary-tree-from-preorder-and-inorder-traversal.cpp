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
    map<int,int> mp;
    TreeNode* fun(int preS,int preE,int inS,int inE,vector<int> &preorder,vector<int> &inorder){
        if(preS>preE||inS>inE)return NULL;
        TreeNode* root=new TreeNode(preorder[preS]);
        int val=preorder[preS];
        int index=mp[val];
        root->left=fun(preS+1,preS+(index-inS),inS,index-1,preorder,inorder);
        root->right=fun(preS+index-inS+1,preE,index+1,inE,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        return fun(0,n-1,0,n-1,preorder,inorder);
    }
};