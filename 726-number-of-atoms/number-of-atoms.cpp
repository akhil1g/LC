class Solution {
public:
    string countOfAtoms(string s) {
        stack<pair<string,int>> st;
        int n=s.length();
        map<string,int> mp;
        string temp="";
        int c=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                if(temp.size())
                {
                    if(flag==false)
                    st.push({temp,1});
                    else
                    st.push({temp,c});
                    temp="";
                    flag=false;
                    c=0;
                }
                temp+=s[i];
            }
            else
            if(s[i]>='a'&&s[i]<='z')
            {
                temp+=s[i];
            }
            else
            if(s[i]>='0'&&s[i]<='9')
            {
                flag=true;
                c*=10;
                c+=(s[i]-'0');
            }
            else
            if(s[i]=='(')
            {
                if(temp.size())
                {
                    if(flag)
                    st.push({temp,c});
                    else
                    st.push({temp,1});
                    c=0;
                    temp="";
                    flag=false;
                }
                st.push({"(",1});
            }
            else
            {
                if(s[i]==')')
                {
                    if(temp.size())
                    {
                        if(flag)
                        st.push({temp,c});
                        else
                        st.push({temp,1});
                        c=0;
                        flag=false;
                        temp="";
                    }
                    int k=i+1;
                    int cnt=0;
                    while(k<n&&s[k]>='0'&&s[k]<='9')
                    {
                        cnt*=10;
                        cnt+=(s[k]-'0');
                        k++;
                    }
                    if(cnt==0)
                    {
                        cnt=1;
                    }
                    i=k-1;
                    stack<pair<string,int>> st1;
                    while(st.size()&&st.top().first!="(")
                    {
                        st1.push({st.top().first,st.top().second*cnt});
                        st.pop();
                    }
                    st.pop();
                    while(st1.size())
                    {
                        st.push({st1.top().first,st1.top().second});
                        st1.pop();
                    }
                }
            }
        }
        if(temp.size())
        {
            if(flag)
            {
                st.push({temp,c});
            }
            else
            {
                st.push({temp,1});
            }
        }
        while(st.size())
        {
            mp[st.top().first]+=st.top().second;
            st.pop();
        }
        string ans="";
        auto it=mp.begin();
        while(it!=mp.end())
        {
            ans+=it->first;
            cout<<it->first<<" "<<it->second<<"\n";
            if(it->second==1)
            {
                it++;
                continue;
            }
            string num=to_string(it->second);
            ans+=num;
            it++;
        }
        return ans;
    }
};