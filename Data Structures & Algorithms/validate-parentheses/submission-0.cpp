class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &u:s)
        {
            if(u=='('||u=='{'||u=='[')
            {
                st.push(u);
            }
            else
            {
                if(st.size()==0)
                {
                    return false;
                }
                else if(u==')')
                {
                    if(st.top()!='(')return false;
                    else st.pop();
                }
                else if(u=='}')
                {
                    if(st.top()!='{')return false;
                    else st.pop();
                }
                else if(u==']')
                {
                    if(st.top()!='[')return false;
                    else st.pop();
                }
            }
        }
        return st.size()==0;
    }
};
