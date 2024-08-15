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
    void flatten(TreeNode* root) {
       stack<TreeNode*> st;
       st.push(root);
       if(root==NULL) return;
       while(st.size()){
        TreeNode* top=st.top();
        st.pop();
        if(top->right){
            st.push(top->right);
        }
        if(top->left){
            st.push(top->left);
        }
        if(st.size()){
            top->right=st.top();
        }
        top->left=NULL;
       }
    }
};