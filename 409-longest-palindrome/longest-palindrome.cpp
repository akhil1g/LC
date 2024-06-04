class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
    for (char c : s) 
        mp[c]++;
    int ans = 0;
    bool hasOdd = false;
    for (auto& pair : mp) {
        int count = pair.second;
        ans += (count / 2) * 2;
        if (count % 2 == 1) {
            hasOdd = true;
        }
    }
    if (hasOdd) {
        ans += 1;
    }
    return ans;
    }
};