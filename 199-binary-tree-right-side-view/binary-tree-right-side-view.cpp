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
    void getright(TreeNode* root,vector<int> &ans){
        if(!root)
        return;
        ans.push_back(root->val);
        if(root->right){
            getright(root->right,ans);
        }
        else{
            getright(root->left,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // getright(root,ans);

        queue<TreeNode*> q;
        q.push(root);
        if(!root)
        return ans;
        while(q.size()){
            int r=q.size();
            for(int i=0;i<r;i++){
                TreeNode*front=q.front();
                q.pop();
                if(i==r-1){
                    ans.push_back(front->val);
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){{
                    q.push(front->right);
                }}
            }
        }
        return ans;
    }
};