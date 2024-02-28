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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return root->val;
        if(root->left==NULL&&root->val==0)
        return root->right->val;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                if(front->left)
                {
                    v.push_back(front->left->val);
                    q.push(front->left);
                }
                if(front->right)
                {
                    v.push_back(front->right->val);
                    q.push(front->right);
                }
            }
            if(!v.empty())
            ans.push_back(v);
        }
        if(ans.size()==1)
        return root->val;
        else { return ans[ans.size()-1][0];}
    }
};