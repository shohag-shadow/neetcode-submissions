class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        int i=0,j=0,ansl=-1,ansr=s.size()+100,count=0;
        int mp[100]={0};
        int mp1[100]={0};
        for(auto &u:t)
        {
            mp[u-'A']++;
        }
        while(j<s.size())
        {
            mp1[s[j]-'A']++;
            if(mp1[s[j]-'A']<=mp[s[j]-'A'])
            {
                count++;
            }
            while(count>=t.size()&&i<=j)
            {
                if(ansr-ansl+1>j-i+1)
                {
                    ansl=i;
                    ansr=j;
                }
                if(mp1[s[i]-'A']<=mp[s[i]-'A'])
                {
                    count--;
                }
                mp1[s[i]-'A']--;
                i++;
            }
            j++;
        }
        if(ansl==-1)return "";
        return s.substr(ansl,ansr-ansl+1);
    }
};
