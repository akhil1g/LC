using ll=long long int;
class Solution {
public:
    int dp[201][201][201][2];
    ll mod=1e9+7;
    int f(int one,int zero,int o,int z,int pre,int cnt,int limit)
    {
        if(one==o&&zero==z)
            return 1;
        if(dp[one][zero][cnt][pre]!=-1)
            return dp[one][zero][cnt][pre];
        int tk=0;
        if(one<o)
        {
            if(pre==1)
            {
                if(cnt+1<=limit)
                tk=((tk%mod)+f(one+1,zero,o,z,1,cnt+1,limit)%mod)%mod;
            }
            else 
                tk=((tk%mod)+f(one+1,zero,o,z,1,1,limit)%mod)%mod;
        }
       if(zero<z)
       {
           if(pre==0)
           {
               if(cnt+1<=limit)
                   tk=((tk%mod)+f(one,zero+1,o,z,0,cnt+1,limit)%mod)%mod;
           }
           else if(pre==1)
               tk=((tk%mod)+f(one,zero+1,o,z,0,1,limit)%mod)%mod;
       }
        return dp[one][zero][cnt][pre]=tk%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
       
        // memset(dp,-1,sizeof(dp));
        for(int i=0; i<=one; i++){
            for(int j=0; j<=zero; j++){
                for(int k=0; k<=limit; k++){
                    for(int l=0; l<2; l++){
                        dp[i][j][k][l]=-1;
                    }
                    
                }
            }
        }
        int ans=f(0,0,one,zero,0,0,limit);
        return ans%mod;
    }
};