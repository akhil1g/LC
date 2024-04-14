class Solution {
public:
     unordered_map<int,unordered_map<int,unordered_map<int,int>>> m;

    int solve(int i,int j,int x,vector<int>&nums,vector<int>&a){
        if(j>=a.size()&&i>=nums.size()) return 0;
        if(i>=nums.size()||j>=a.size()) return 1e9;
        
         if(m.count(i) && m[i].count(j) && m[i][j].count(x)) 
            return m[i][j][x];
    
        int ans=1e9;
        
        int y=x&nums[i];
        if(y==a[j]){
        ans=min(ans,nums[i]+solve(i+1,j+1,INT_MAX,nums,a));      
        }
        ans=min(ans,solve(i+1,j,y,nums,a));
          return m[i][j][x]=ans;
       
    }
    int minimumValueSum(vector<int>& nums, vector<int>& a) {
    
    int ans=solve(0,0,INT_MAX,nums,a);
        if(ans>=1e9) return -1;
        return ans;
    }
};