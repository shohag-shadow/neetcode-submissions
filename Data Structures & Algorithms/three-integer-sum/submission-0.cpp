class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s=-1*(nums[i]+nums[j]);
                int l=j+1,r=n-1;
                while(l<=r)
                {
                    int m=(l+r)/2;
                    if(nums[m]>s)r=m-1;
                    else if(nums[m]<s)l=m+1;
                    else 
                    {
                        ans.insert({nums[i],nums[j],nums[m]});
                        break;
                    }
                }
            }
        }
        vector<vector<int>>out;
        for(auto u:ans)out.push_back(u);
        return out;
    }
};
