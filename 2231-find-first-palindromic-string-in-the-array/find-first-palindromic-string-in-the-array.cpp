class Solution {
public:
    bool check(string &s ,int st,int end)
    {
        while(st<=end)
        {
            if(s[st]!=s[end])
            return false;
            st++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(check(words[i],0,words[i].size()-1))
            return words[i];
        }
        return "";
    }
};