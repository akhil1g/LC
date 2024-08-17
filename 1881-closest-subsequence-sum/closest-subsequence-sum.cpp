using ll=long long;
class Solution {
public:
    void fun(int index,ll sum,int n,vector<int> &nums,vector<ll> &arr){
        if(index==n){
            arr.push_back(sum);
            return ;
        }
        fun(index+1,sum+nums[index],n,nums,arr);
        fun(index+1,sum,n,nums,arr);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        ll ans=1e9;
        int n=nums.size();
        vector<ll> left,right;
        int mid=n/2;

        fun(0,0,mid,nums,left);
        fun(mid,0,n,nums,right);
        sort(right.begin(),right.end());
        for(int i=0;i<left.size();i++){
            int index=lower_bound(right.begin(),right.end(),goal-left[i])-right.begin();
            if(index==right.size()){
                index--;
            }
            if(index+1<right.size())
            ans=min(ans,abs(goal-left[i]-right[index+1]));
            ans=min(ans,abs(goal-(left[i]+right[index])));
            if(index>0)
            ans=min(ans,abs(goal-left[i]-right[index-1]));
        }
        return ans;
    }
};