class Solution {
public:
    int mod=1e9+7;
    int dp[201][201][201][2];
    int fun(int ones,int zeros,int l,int prev,int n,int one,int zero,int limit,int dp[201][201][201][2])
    {
        if(ones+zeros==n)
        {
            return 1;
        }
        if(dp[ones][zeros][l][prev]!=-1)
        {
            return dp[ones][zeros][l][prev];
        }
        int ans=0;
        if(l==limit)
        {
            if(prev==1)
            {
                if(zeros<zero)
                {
                    ans=(ans+fun(ones,zeros+1,1,0,n,one,zero,limit,dp)%mod)%mod;
                }
            }
            if(prev==0)
            {
                if(ones<one)
                {
                    ans=(ans+fun(ones+1,zeros,1,1,n,one,zero,limit,dp)%mod)%mod;
                }
            }
        }
        else
        {
            if(zeros<zero)
            {
                if(prev==0)
                {
                    ans=(ans+fun(ones,zeros+1,l+1,0,n,one,zero,limit,dp)%mod)%mod;
                }
                else
                ans=(ans+fun(ones,zeros+1,1,0,n,one,zero,limit,dp)%mod)%mod;
            }
            if(ones<one)
            {
                if(prev==1)
                {
                    ans=(ans+fun(ones+1,zeros,l+1,1,n,one,zero,limit,dp)%mod)%mod;
                }
                else
                ans=(ans+fun(ones+1,zeros,1,1,n,one,zero,limit,dp)%mod)%mod;
            }
        }
        return dp[ones][zeros][l][prev]=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        int n=zero+one;
        memset(dp,-1,sizeof(dp));
        int ans= fun(0,0,0,0,n,one,zero,limit,dp);
        return ans;
        
    }
};