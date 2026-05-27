class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        unordered_map<char,int>s1map,s2map;
        for(auto &u:s1)s1map[u]++;
        int i=0,j=0;
        int have=0,extra=0;
        while(j<s1.size())
        {
            s2map[s2[j]]++;
            if(s2map[s2[j]]<=s1map[s2[j]])
            {
                have++;
            }
            if(have==s1.size())return true;
            j++;
        }
        while(j<s2.size())
        {
            //cout<<i<<" "<<j<<endl;
            s2map[s2[j]]++;
            if(s2map[s2[j]]<=s1map[s2[j]])
            {
                have++;
            }
            if(s2map[s2[i]]<=s1map[s2[i]])
            {
                have--;
            }
            s2map[s2[i]]--;
            if(have==s1.size())return true;
            j++;
            i++;
        }
        return false;
    }
};
