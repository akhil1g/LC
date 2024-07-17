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
    void remove(TreeNode* &root,unordered_map<int,int> &m,vector<TreeNode*> &ans)
    {
        if(root==NULL)
        return ;
        remove(root->left,m,ans);
        remove(root->right,m,ans);
        if(m.find(root->val)!=m.end())
        {
            if(root->left)
            ans.push_back(root->left);
            if(root->right)
            ans.push_back(root->right);
            root=NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int,int> m;
        for(int i=0;i<to_delete.size();i++)
        m[to_delete[i]]++;
        remove(root,m,ans);
        if(root)
        ans.push_back(root);
        return ans;
    }
};