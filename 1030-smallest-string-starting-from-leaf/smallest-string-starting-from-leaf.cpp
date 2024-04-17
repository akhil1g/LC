class Solution {
public:
    void path(TreeNode* root,string s,vector<string> &ans)
    {
        if(root==NULL) return ; 
        s+=root->val+97;
        if(root->left==NULL&&root->right==NULL)
        {
            reverse(s.begin(),s.end());
            if(ans.size()==0) ans.push_back(s);
            else
            {
                if(lexicographical_compare(s.begin(),s.end(),ans[ans.size()-1].begin(),ans[ans.size()-1].end()))
                ans[ans.size()-1]=s;
            }
        }
        path(root->left,s,ans);
        path(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
     vector<string> ans;
     string s="";
     path(root,s,ans);   
     return ans[ans.size()-1];
    }
};