#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using ll=long long;
ll mod=1e9+7;
class Solution {
public:
    ll binpow(ll a,ll b) 
    { 
        a%=mod; 
        ll res=1; 
        while(b>0) 
        { 
            if(b&1) 
            res=(res*a)%mod; 
            a=(a*a)%mod; 
            b>>=1; 
        } 
        return res%mod; 
    }
    int minimumTimeToInitialState(string s, int k) {
        ll n=s.size(); 
        vector<ll> v(n+1,0);
        ll c=0;
        for(ll i=0;i<n;i++)
        {
            c=(c+(binpow(31LL,i)*(s[i]-'a'))%mod)%mod;
            v[i+1]=c;
        }
        c=1;
        ll  ans=ceil(n*1.0/k);
        for(ll  i=k;i<n;i+=k)
        {
            ll  l=n-i;
            ll  hs1=(v[n]-v[i]+mod)%mod;
            ll  hs2=((v[l]%mod)*binpow(31LL,i))%mod;
            if(hs1==hs2)
            {
                ans=c;
                break;
            }
            c++;
        }
        return ans;
    }
};