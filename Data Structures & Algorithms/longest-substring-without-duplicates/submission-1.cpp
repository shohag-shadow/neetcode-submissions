class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        set<char>st;
        int i=0,j=0,ans=1;
        st.insert(s[0]);
        while(j<s.size()-1)
        {
            j++;
            if(st.count(s[j]))
            {
                while(s[i]!=s[j])
                {
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans=max(ans,j-i+1);
            //cout<<i<<" "<<j<<endl;
        }
        return ans;
    }
};
