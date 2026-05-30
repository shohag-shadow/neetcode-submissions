class Solution {
    bool possible(vector<int>& piles,int s,int h)
    {
        int t =0;
        for(auto u:piles)
        {
            t+=u/s+(u%s>0);
        }
        return t<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1000000000,ans=-1,m;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(possible(piles,m,h))
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};
