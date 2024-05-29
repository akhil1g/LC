class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num>0)
        {
            if(num&1)
            {
                num--;
                ans++;
            }
            else
            {
                ans++;
                num/=2;
            }
        }
        return ans;
    }
};