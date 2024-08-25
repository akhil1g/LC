class Solution {
public:
    int fun(int index,int k,string &s,vector<int> &dp){
        if(index>=s.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=1e9;
        long long c=0;
        for(int i=index;i<s.size();i++){
            c*=10;
            c+=(s[i]-'0');
            if(c<=k){
                ans=min(ans,1+fun(i+1,k,s,dp));
            }
            else
            break;
        }
        return dp[index]=ans;
    }
    int minimumPartition(string s, int k) {
        int n=s.size();
        vector<int> dp(n,-1);
        int ans=fun(0,k,s,dp);
        return ans!=1e9?ans:-1;
    }
};