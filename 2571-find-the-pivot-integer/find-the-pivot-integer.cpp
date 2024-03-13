using ll=long long;
class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        for(int i=2;i<n;i++)
        {
            ll s=i-1;
            s=(s*(s+1)/2);
            ll x=(n*(n+1)/2);
            ll x1=(i*(i+1)/2);
            x-=x1;
            if(s==x)
            return i;
        }
        return -1;
    }
};