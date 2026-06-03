class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lmx=height[l],rmx=height[r];
        int ans=(r-l+1)*min(lmx,rmx)-2*min(lmx,rmx);
        while(l<r)
        {
            int h=min(lmx,rmx);
            if(height[l]<height[r])
            {
                l++;
                lmx=max(lmx,height[l]);
                ans+=(r-l+1)*min(lmx,rmx)-(r-l+1)*h;
                ans-=min(height[l],h);
            }
            else
            {
                r--;
                rmx=max(rmx,height[r]);
                ans+=(r-l+1)*min(lmx,rmx)-(r-l+1)*h;
                ans-=min(height[r],h);
            }
        }
        return ans;
    }
};
