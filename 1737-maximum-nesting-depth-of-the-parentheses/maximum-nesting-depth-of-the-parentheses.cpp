class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int ans=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            p++;
            else
            if(s[i]==')')
            {
                ans=max(ans,p);
                p--;
            }
        }
        return ans;
    }
};