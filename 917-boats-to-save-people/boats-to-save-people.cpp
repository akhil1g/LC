class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s=0,e=people.size()-1,p=0,n=people.size();
        while(s<e)
        {
            if(people[s]+people[e]<=limit)
            {
                p++;
                s++;
                e--;
            }
            else
            if(people[s]+people[e]>limit)
            e--;
        }
        return p+(n-(2*p));
    }
};