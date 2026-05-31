class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {
    {-1,-1},{-1,0},{-1,1},
    { 0,-1},       { 0,1},
    { 1,-1},{ 1,0},{ 1,1}
};
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<tuple<int,int,int>> q;
        visited[0][0] = true;
        q.push({0,0,1});
        while(!q.empty()){
            auto [i,j,dist] = q.front();
            q.pop();
            if(i == n-1 && j == n-1){
                return dist;
            }
            for(auto [dr , dc] : dirs){
                int ni = i+dr;
                int nj = j+dc;
                if(grid[0][0] == 1 || grid[n-1][n-1] == 1 ){
                    return -1;
                }
                if(ni < 0 || ni >= n || nj < 0 || nj >= n || grid[ni][nj] == 1 || visited[ni][nj]){
                    continue;
                }
                if(!visited[ni][nj] && grid[ni][nj] == 0){
                    visited[ni][nj] = true;
                    q.push({ni,nj,dist+1});
                }
            }
            
        }
        return -1;
    }
};