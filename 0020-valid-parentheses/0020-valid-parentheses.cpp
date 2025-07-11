class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        stack<char> stk;
        if(s.length() == 1) return false;
        while(i != s.length()){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()) return false;
                if(s[i] == '}'){
                    if(stk.top() == '{') stk.pop();
                    else return  false;
                }
                else if(s[i] == ')'){
                    if(stk.top() == '(') stk.pop();
                    else return  false;
                }
                else if(s[i] == ']'){
                    if(stk.top() == '[') stk.pop();
                    else return  false;
                }
            }
            i++;
        }
        if(!stk.empty()) return false;
        return true;
    }
};