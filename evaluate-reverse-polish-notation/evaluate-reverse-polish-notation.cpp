class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string token:tokens){
            if(token=="+"){
               int op1 = stoi(st.top());
                st.pop();
               int op2 = stoi(st.top());
                st.pop();
               st.push(to_string(op1+op2)); 
            }else if (token=="-"){
                int op1 = stoi(st.top());
                st.pop();
               int op2 = stoi(st.top());
                st.pop();
               st.push(to_string(op2-op1)); 
            }else if (token=="/"){
                int op1 = stoi(st.top());
                st.pop();
               int op2 = stoi(st.top());
                st.pop();
               st.push(to_string(op2/op1)); 
            }else if (token=="*"){
                int op1 = stoi(st.top());
                st.pop();
               int op2 = stoi(st.top());
                st.pop();
               st.push(to_string(op1*op2)); 
            }else {
                st.push(token);
            }
        }
        return stoi(st.top());
        
    }
};