class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int st=0,end=n-1;
        char ch=s[st];
        if(s[st]!=s[end])
        return n;
        while(st<end)
        {
            if(s[st]==s[end])
            {
                ch=s[st];
                while(st<n&&s[st]==ch)
                st++;
                while(end>0&&s[end]==ch)
                end--;
            }
            else
            {
                break;
            }
        }
        return max(0,end-st+1);
    }
};