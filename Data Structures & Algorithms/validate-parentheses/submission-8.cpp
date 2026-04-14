class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() % 2 != 0){
            return false;
        }
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                if(st.empty()) return false;
                if((c == ')' && st.top() == '(')
                || (c == '}' && st.top() == '{')
                || (c == ']' && st.top() == '[')
                ){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
