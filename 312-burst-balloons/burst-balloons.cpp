class Solution {
public:
    int fun(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i>j)
        return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,(nums[i-1]*nums[k]*nums[j+1])+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(1);
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        temp.push_back(1);
        n=temp.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(1,n-2,temp,dp);
    }
};