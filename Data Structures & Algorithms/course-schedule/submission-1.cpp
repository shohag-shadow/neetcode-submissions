class Solution {
public:
    bool toposort(int node,vector<int>graph[],vector<bool>istaken)
    {
        if(istaken[node])return false;
        istaken[node]=true;
        for(auto child:graph[node])
        {
            if(!toposort(child,graph,istaken))return false;
        }
        istaken[node]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses+1];
        for(auto u:prerequisites)graph[u[0]].push_back(u[1]);
        vector<bool>istaken(numCourses+1,false);
        bool ans=true;
        for(int i=0;i<numCourses;i++)
        {
            if(istaken[i]==false)ans&=toposort(i,graph,istaken);
            if(ans==false)break;
        }
        return ans;
    }
};
