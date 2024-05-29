class Solution {
public:
    int minMoves(int target, int d) {
        int ans=0;
        while(target!=1)
        {
            if(target&1)
            {
                ans++;
                target--;
            }
            else
            {
                if(d>0)
                {
                    target/=2;
                    ans++;
                    d--;
                }
                else
                {
                    ans+=target-1;
                    break;
                }
            }
        }
        return ans;
    }
};