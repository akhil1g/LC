class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int num=s[i]-'0';
            if(st.size()==0)
            {
                st.push(num);
                continue;
            }
            if(num<st.top())
            {
                while(st.size()&&num<st.top()&&k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(num);
            }
            else
            st.push(num);
        }
        // cout<<k<<"\n";
        while(k>0&&st.size())
        {
            st.pop();
            k--;
        }
        string ans="";
        while(st.size())
        {
            ans+=(st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ind=0;
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='0')
            ind++;
            else
            break;
        }
        if(ind==ans.length())
        return "0";
        return ans.substr(ind);
    }
};