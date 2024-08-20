class Solution {
public:
    map<vector<int>,int> mp;
    vector<vector<int>> ans;
    void fun(int st,int k,int n,map<int,int> temp,vector<int> t){
        if(n==0){
            if(k==0){
                if(mp.find(t)==mp.end()){
                    ans.push_back(t);
                }
                mp[t]++;
            }
            return;
        }
        if(k==0){
            return;
        }
        for(int i=st;i<=9;i++){
            if(temp.find(i)==temp.end()&&i<=n){
                temp[i]++;
                t.push_back(i);
                fun(i+1,k-1,n-i,temp,t);
                temp.erase(i);
                t.pop_back();
            }
            else
            if(i>n)
            break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        map<int,int> temp;
        fun(1,k,n,temp,{});
        return ans;
    }
};