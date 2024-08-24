class Solution {
public:
    bool check(string &s,int st,int end){
        if(st==end&&st==s.size())
        return false;
        if(st>end)
        return false;
        while(st<end){
            if(s[st]!=s[end])
            return false;
            st++;
            end--;
        }
        return true;
    }
    bool fun(int index,int k,string &s,vector<vector<int>> &dp){
        if(k==2){
            return check(s,index,s.size()-1);
        }
        if(index==s.size())
        {
            return false;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        bool ans=false;
        for(int i=index;i<s.size();i++){
            if(k<2&&check(s,index,i)){
                ans|=fun(i+1,k+1,s,dp);
                if(ans==true){
                    break;
                }
            }
        }
        return dp[index][k]=ans;
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return fun(0,0,s,dp);
    }
};