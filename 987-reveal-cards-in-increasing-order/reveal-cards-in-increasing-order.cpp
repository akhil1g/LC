class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(),deck.rend());
        int n=deck.size();
        vector<int> ans(n);
        deque<int> dq;
        dq.push_front(deck[0]);
        for(int i=1;i<n;i++)
        {
            int r=dq.back();
            // cout<<r<<" ";
            dq.pop_back();
            dq.push_front(r);
            dq.push_front(deck[i]);
        }
        int i=0;
        while(dq.size())
        {
            ans[i]=dq.front();
            dq.pop_front();
            i++;
        }
        return ans;
    }
};