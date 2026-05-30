class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        for(int i=0;i<position.size();i++)v.push_back({position[i],speed[i]});
        sort(v.begin(),v.end());
       stack<double>st;
       int ans=0;
       for(int i=position.size()-1;i>=0;i--)
       {
            double t=((target-v[i].first)*(1.000))/v[i].second;
            while(st.size()&&st.top()<t)
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans++;
            }
            st.push(t);
       }
       return ans;
    }
};
