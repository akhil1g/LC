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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(!root)
        return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            for(int i=0;i<q.size();i++)
            {
                TreeNode * front=q.front();
                q.pop();
                if(front->left)
                {
                    if(front->left->left==NULL&&front->left->right==NULL)
                    {
                        ans+=front->left->val;
                    }
                    else
                    {
                        q.push(front->left);
                    }
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};