using ll=long long;
class Solution {
public:
    int mostBooked(ll n, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        ll ans=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        map<ll,ll> mp;
        ll freq=0;
        vector<ll> room(n,0);
        for(ll i=0;i<m.size();i++)
        {
                if(pq.size()==0)
                {
                    pq.push({m[i][1],0});
                    mp[0]++;
                    room[0]=m[i][1];
                }
                else
                {
                    ll r=pq.size();
                    ll c=-1;
                    for(ll j=0;j<r;j++)
                    {
                        if(room[j]<=m[i][0])
                        {
                            c=j;
                            break;
                        }
                    }
                    if(c!=-1)
                    {
                        vector<pair<ll,ll>> temp;
                        mp[c]++;
                        room[c]=m[i][1];
                        pair<ll,ll> p;
                        while(pq.size())
                        {
                            ll f=pq.top().first;
                            ll s=pq.top().second;
                            pq.pop();
                            if(s==c)
                            {
                                p={f,s};
                                break;
                            }
                            temp.push_back({f,s});
                        }
                        for(ll i=0;i<temp.size();i++)
                            pq.push({temp[i].first,temp[i].second});
                        pq.push({m[i][1],c});
                    }
                    else
                    {
                        ll r=pq.size();
                        if(r<n)
                        {
                            pq.push({m[i][1],r});
                            room[r]=m[i][1];
                            mp[r]++;
                        }
                        else
                        if(r==n)
                        {
                            ll f=pq.top().first;
                            ll s=pq.top().second;
                            pq.pop();
                            mp[s]++;
                            room[s]+=(m[i][1]-m[i][0]);
                            pq.push({f+m[i][1]-m[i][0],s});
                        }
                    }
                }
        }
        auto it=mp.begin();
        while(it!=mp.end())
        {
            if(it->second>freq)
            {
                freq=it->second;
                ans=it->first;
            }
            else
            if(it->second==freq)
            {
                ans=min(ans,it->first);
            }
            it++;
        }
        return ans;
    }
};