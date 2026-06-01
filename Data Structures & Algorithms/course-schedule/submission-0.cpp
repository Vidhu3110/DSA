class Solution {
public:
    vector<int> state;
    vector<vector<int>> adj;

    bool DFS(int node){
        state[node] = 1;

        for(auto v : adj[node]){
            if(state[v] == 1)  return true;
            if(state[v] == 0){
                if(DFS(v))  return true;
            }
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        state.assign(numCourses,0);
        adj.resize(numCourses);

        // build adj list
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        //call dfs now 

        for(int i = 0 ; i < numCourses;i++){
            if(state[i] == 0){
                if(DFS(i)){
                    return false;
                }
            }
        }
        return true;
    }
};
