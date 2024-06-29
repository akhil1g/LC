class Solution {
public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(j==t.length())
        return 1;
        if(i==s.length())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
        {
            ans+=fun(i+1,j+1,s,t,dp);
            ans+=fun(i+1,j,s,t,dp);
        }
        else
        {
            ans+=max(ans,fun(i+1,j,s,t,dp));
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return fun(0,0,s,t,dp);
    }
};