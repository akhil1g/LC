class Solution 
{
public:
    int fun(int index,int j, string ring, string key,int m,int n, vector<vector<int>>&dp)
    {
        if(j==n)
          return 0;
        if(dp[index][j]!=-1)
          return dp[index][j];
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(ring[i]==key[j])
            {
                int count = min(abs(index-i),m-abs(index-i));
                ans = min(ans, count + fun(i, j+1, ring, key, m, n,dp));
            }
        }
        return dp[index][j]=ans;
    }
    int findRotateSteps(string ring, string key)
    {
        int n = key.size();
        int m = ring.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return fun(0,0,ring, key,m,n,dp)+n;
    }
};