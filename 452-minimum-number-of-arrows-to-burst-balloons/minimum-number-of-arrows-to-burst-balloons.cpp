class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> v;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            if(v.size()==0)
            v.push_back(points[i]);
            else
            if(points[i][0]<=v.back()[1])
            {
                v.back()[0]=max(v.back()[0],points[i][0]);
                v.back()[1]=min(v.back()[1],points[i][1]);
            }
            else
            v.push_back(points[i]);
        }
        return v.size();
    }
};