class Solution {
public:
    int fun(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i1>=s1.length()||i2>=s2.length())
        return 0;
        if(dp[i1][i2]!=-1)
        return dp[i1][i2];
        int ans=0;
        if(s1[i1]==s2[i2])
        ans=max(ans,1+fun(i1+1,i2+1,s1,s2,dp));
        else
        {
            ans=max(ans,fun(i1+1,i2,s1,s2,dp));
            ans=max(ans,fun(i1,i2+1,s1,s2,dp));
        }
        return dp[i1][i2]=ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return fun(0,0,s1,s2,dp);
    }
};