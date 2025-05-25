class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool entered = false;
        for (char c : s){
            if(c == '(' || c== '{' || c=='['){
                st.push(c);
            }else if (c == ')' && (((!st.empty() && st.top() != '(')) || st.empty())){
                return false;
            }else if (c == ']' && (((!st.empty() && st.top() != '[')) || st.empty())){
                return false;
            }else if (c == '}' && (((!st.empty() && st.top() != '{')) || st.empty())){
                return false;
            }else {
                st.pop();
            }
        }
        return st.size() == 0;
    }
};