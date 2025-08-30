class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int len = 0;
        map<char,int> mp;
        for(int j=0;j<s.size();j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]]+1);
            }
            mp[s[j]] = j;
            len = max(len, j-i+1);
        }
        return len;
    }
};