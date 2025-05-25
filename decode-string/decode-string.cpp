class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        string ans;
        for (char c : s){
            if(c == ']'){
                string tmp;
                string num;
                while (!st.empty() && st.top()>='a' && st.top()<='z'){
                    tmp += st.top();
                    st.pop();
                }
                reverse(tmp.begin(),tmp.end());
                st.pop();
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                string all;
                if(num.size()==0){
                    for (char ll : tmp){
                        st.push(ll);
                    }
                }else {
                    int n = stoi(num);
                    while(n--){
                        all += tmp;
                    }
                    for(char ll:all){
                        st.push(ll);
                    }
                }
                
            }else {
                st.push(c);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};