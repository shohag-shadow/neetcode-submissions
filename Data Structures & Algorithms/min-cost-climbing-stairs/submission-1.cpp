class Solution {
    int dp[103];
    int func(int n,vector<int>&cost)
    {
        if(n>=cost.size())return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=cost[n]+min(func(n+1,cost),func(n+2,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=0;i<cost.size();i++)dp[i]=-1;
        return min(func(0,cost),func(1,cost));
    }
};
