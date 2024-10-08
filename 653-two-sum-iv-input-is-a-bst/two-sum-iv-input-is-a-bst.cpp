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
    bool fun(TreeNode* root,int k){
        if(!root) return false;
        bool ans=false;
        ans|=fun(root->left,k);
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp[root->val]++;
        ans|=fun(root->right,k);
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        return fun(root,k);
    }
};