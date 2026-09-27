class Solution {
public:
    string reverseParentheses(string s) {
        string st = "";
        for(char c : s){
            if(c == ')'){
                string temp = "";
                while(st.back() != '('){
                    temp += st.back();
                    st.pop_back();
                }
                st.pop_back();
                for(char c : temp){
                    st += c;
                }
            }
            else st += c;
        }
        return st;

    }
};