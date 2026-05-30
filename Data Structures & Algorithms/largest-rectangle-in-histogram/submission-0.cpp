class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>>st;
        vector<int>l(n),r(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(st.size()&&st.top().first>=heights[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                l[i]=i+1;
            }
            else
            {
                l[i]=(i-st.top().second);
            }
            st.push({heights[i],i});
        }
        while(st.size())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()&&st.top().first>=heights[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                r[i]=(n-i);
            }
            else
            {
                r[i]=(st.top().second-i);
            }
            st.push({heights[i],i});
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(l[i]+r[i]-1)*heights[i]);
            //cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
        return ans;
    }
};
