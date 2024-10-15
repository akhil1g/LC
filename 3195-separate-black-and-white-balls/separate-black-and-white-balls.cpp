using ll=long long;
class Solution {
public:
    long long minimumSteps(string s) {
        ll ans=0;
        ll n=s.size();
        string t=s;
        sort(t.begin(),t.end());
        ll k=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=(i-k);
                k++;
            }
        }
        return ans;
    }
};