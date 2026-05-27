class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (string s : strs)
        {
            for (char c : s)
            {
                if ( c == 'A')
                {
                    ans.push_back('.');
                }
                ans.push_back(c);
            }
            ans.push_back('A');
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        bool is_slash=false;
        string tmp;
        for(auto u:s)
        {
            if(u=='.')
            {
                if(is_slash)tmp.push_back('.');
                is_slash=true;
            }
            else if(u=='A')
            {
                if(is_slash)
                {
                    tmp.push_back('A');
                    is_slash=false;
                }
                else
                {
                    ans.push_back(tmp);
                    tmp.clear();
                }
            }
            else
            {
                if(is_slash)
                {
                    tmp.push_back('.');
                    is_slash=false;
                }
                tmp.push_back(u);
            }
        }
        return ans;
    }
};
