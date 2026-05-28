class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
       for(auto u:tokens)
       {
            if(u=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(u=="-")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(u=="*")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(u=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else
            {
                st.push(stoi(u));
            }
       } 
       return st.top();
    }
};
