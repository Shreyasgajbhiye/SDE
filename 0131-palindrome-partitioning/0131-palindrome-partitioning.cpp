class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;

    bool checkpal(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    void backTrack(string s, int idx, vector<string> &curr, vector<vector<string>> &res){
        if(idx == s.size()){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(checkpal( s,  idx,  i)){
                curr.push_back(s.substr(idx, i-idx+1));
                backTrack(s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        backTrack(s, 0, curr, res);
        return res;
    }
};