/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 using ll=unsigned long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll,TreeNode*>> q;
        q.push({0,root});
        ll ans=0;
        while(q.size()){
            ll r=q.size();
            ll f=0,l=0;
            for(ll i=0;i<r;i++){
                TreeNode* front=q.front().second;
                ll index=q.front().first;
                if(i==0){
                    f=index;
                }
                if(i==r-1){
                    l=index;
                }
                q.pop();
                if(front->left){
                    q.push({2*index+1,front->left});
                }
                if(front->right){
                    q.push({2*index+2,front->right});
                }
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }
};