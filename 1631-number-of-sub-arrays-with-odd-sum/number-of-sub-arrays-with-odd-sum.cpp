class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0,even=0;
        int s=0;
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(s&1){
                odd++;
                ans=(ans+1)%mod;
                ans=(ans+even)%mod;
            }
            else{
                even++;
                ans=(ans+odd)%mod;
            }
        }
        return ans;
    }
};