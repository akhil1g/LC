class Solution {
public:
    int fun(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i>j)
        return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<=j;k++){
            mini=min(mini,nums[j+1]-nums[i-1]+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp));
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int> nums;
        nums.push_back(0);
        sort(cuts.begin(),cuts.end());
        for(int i=0;i<cuts.size();i++){
            nums.push_back(cuts[i]);
        }
        nums.push_back(n);
        int n1=nums.size();
        vector<vector<int>> dp(n1,vector<int>(n1,-1));
        return fun(1,n1-2,nums,dp);
    }
};