class Solution {
public:
   unordered_map<int,TreeNode*> m;
   unordered_map<int,int> m1;
   void create(vector<vector<int>> &descriptions,int i)
   {
       if(i==descriptions.size())
       return ;
       TreeNode* root=NULL;
       if(m.find(descriptions[i][0])==m.end())
       {
           TreeNode* r=new TreeNode(descriptions[i][0]);
           m[descriptions[i][0]]=r;
           root=r;
           m1[descriptions[i][0]]=0;
       }
       else
       {
        //    m1[descriptions[i][0]]=1;
           root=m[descriptions[i][0]];
       }
       int x=descriptions[i][0];
       while(i<descriptions.size()&&descriptions[i][0]==x)
       {
           if(descriptions[i][2]==1)
           {
               if(m.find(descriptions[i][1])==m.end())
               {
                   TreeNode* left=new TreeNode(descriptions[i][1]);
                   m[descriptions[i][1]]=left;
                   root->left=left;
                   m1[descriptions[i][1]]=1;
               }
               else
               {
                   m1[descriptions[i][1]]=1;
                   root->left=m[descriptions[i][1]];
               }
           }
           else
           if(descriptions[i][2]==0)
           {
               if(m.find(descriptions[i][1])==m.end())
               {
                   TreeNode* right=new TreeNode(descriptions[i][1]);
                   root->right=right;
                   m[descriptions[i][1]]=right;
                   m1[descriptions[i][1]]=1;
               }
               else
               {
                   root->right=m[descriptions[i][1]];
                   m1[descriptions[i][1]]=1;
               }
           }
           i++;
       }
       create(descriptions,i);
   }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        create(descriptions,0);
        TreeNode* root=NULL;
        unordered_map<int,int>::iterator it=m1.begin();
        while(it!=m1.end())
        {
            if(it->second==0)
            {
                root=m[it->first];
                break;
            }
            it++;
        }
        return root;
    }
};