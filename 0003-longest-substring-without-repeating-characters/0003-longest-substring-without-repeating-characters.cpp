class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c = 0;
        int l = 0;
        map<char, int> mp;
        for(int r = 0;r<s.length();r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]] + 1);
            }
            c = max(c, r-l+1);
            mp[s[r]] = r;
        }
        return c;
    }
};