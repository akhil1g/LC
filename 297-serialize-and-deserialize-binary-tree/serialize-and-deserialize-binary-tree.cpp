/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void fun(TreeNode* root,string &ans){
        if(!root){
            ans.push_back('*');
            return;
        }
        ans+=to_string(root->val);
        ans+=',';
        fun(root->left,ans);
        fun(root->right,ans);
    }

    TreeNode* des(string &s,int &index){
        if(index==s.length())
        return NULL;
        if(s[index]=='*')
        {
            index++;
            return NULL;
        }
        string temp="";
        int i=index;
        for(;i<s.size();i++){
            if(s[i]==',')
            break;
            temp+=s[i];
        }
        index=i+1;
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=des(s,index);
        root->right=des(s,index);
        return root;
    }
    string serialize(TreeNode* root) {
        string ans="";
        fun(root,ans);
        cout<<ans<<"\n";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return des(data,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));