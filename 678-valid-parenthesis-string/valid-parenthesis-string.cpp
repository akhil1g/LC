class Solution {
public:
    // int dp[101][101][101];
    bool fun(int index,int r_one,string &s,vector<vector<int>> &dp){
        if(r_one<0)
        return false;
        if(index<0)
        return r_one==0;
        if(dp[index][r_one]!=-1){
            return dp[index][r_one];
        }
        bool ans=false;
        if(s[index]=='('){
            ans|=fun(index-1,r_one-1,s,dp);
        }
        else
        if(s[index]==')'){
                ans|=fun(index-1,r_one+1,s,dp);
        }
        else
        if(s[index]=='*'){
            ans|=fun(index-1,r_one,s,dp);
            ans|=fun(index-1,r_one-1,s,dp);
            ans|=fun(index-1,r_one+1,s,dp);
        }
        return dp[index][r_one]=ans;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(n-1,0,s,dp);
    }
};