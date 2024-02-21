class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        unsigned int a=0,b=0,l=left,r=right;
        while(l!=0)
        {
            a++;
            l/=2;
        }
        while(r!=0)
        {
            b++;
            r/=2;
        }
        if(a!=b) return 0;
        l=left; r=right;
        unsigned int long ans=l;
        for(unsigned long int i=l+1;i<=r;i++)
        ans&=i;
        return ans;
    }
};