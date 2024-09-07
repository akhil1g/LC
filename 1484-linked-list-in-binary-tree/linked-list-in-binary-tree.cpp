/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool fun(TreeNode* root,ListNode* head,ListNode* temp){
        if(!temp)
        return true;
        if(!root)
        return false;
        bool ans=false;
        if(root->val==temp->val){
            temp=temp->next;
        }
        else{
            temp=head;
        }
        ans|=fun(root->left,head,temp);
        ans|=fun(root->right,head,temp);
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return fun(root,head,head)|isSubPath(head,root->left)|isSubPath(head,root->right);
    }
};