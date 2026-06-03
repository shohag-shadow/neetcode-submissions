class Solution {
    int dp[49];
public:
    int func(int n)
    {
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=func(n-1)+func(n-2);
    }
    int climbStairs(int n) {
        for(int i=1;i<=n;i++)dp[i]=-1;
        return func(n);
    }
};
