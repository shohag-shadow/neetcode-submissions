class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,n=s.size();
        unordered_map<char,int>mp;
        mp[s[j]]=1;
        int mxlen=1,ans=1;
        while(j<n-1)
        {
            j++;
            mp[s[j]]++;
            if(mp[s[j]]>mxlen)
            {
                mxlen=mp[s[j]];
            }
            while(j-i+1-mxlen>k)
            {
                mp[s[i]]--;
                i++;

            }
            ans=max(j-i+1,ans);
        }
        return ans;
    }
};
