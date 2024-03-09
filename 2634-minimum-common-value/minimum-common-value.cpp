class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        map<int,int> mp;
        for(int i=0;i<n1;i++)
        mp[nums1[i]]++;
        for(int i=0;i<n2;i++)
        if(mp[nums2[i]]>0)
        return nums2[i];
        return -1;
    }
};