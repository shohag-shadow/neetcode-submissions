class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1)return 0;
        int n=nums.size();
        int l=0,r=n-1;
        int ans=1000000;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            ans=min(ans,nums[m]);
            if(nums[l]<=nums[m])
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return ans;
    }
};
