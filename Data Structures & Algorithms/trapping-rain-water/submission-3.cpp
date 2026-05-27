class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),mx=INT_MIN;
        vector<int>prefixmx;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,height[i]);
            prefixmx.push_back(mx);
        }
        mx=INT_MIN;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,height[i]);
            int h=min(mx,prefixmx[i]);
            ans+=h-height[i];
        }
        
        return ans;
    }
};
