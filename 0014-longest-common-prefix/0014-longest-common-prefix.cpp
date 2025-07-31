class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        string s = "";
        int i = 0;
        while(i < s1.size() && s1[i] == s2[i]){
            s+= s1[i];
            i++;
        }
        return s;
    }
};