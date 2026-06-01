class Solution {
public:
    bool isValid(int i , int j , int row , int col , vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0 || visited[i][j]){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int max_time=0;
        int row = grid.size();
        int col = grid[0].size();
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int freshCount = 0;
        for(int i = 0; i < row ; i++){
            for(int j = 0 ; j <col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        while(!q.empty()){
            auto [i,j,rottenTime] = q.front();
            q.pop();
            for(auto [dr,dc] : dirs){
                int ni = i + dr;
                int nj = j + dc;

                if(isValid(ni,nj,row,col,grid,visited) && grid[ni][nj] == 1){
                    visited[ni][nj] = true;
                    q.push({ni,nj,rottenTime+1});
                    max_time = rottenTime+1;
                    freshCount--;
                }
            }
        }
        if(freshCount > 0)  return -1;
        return max_time;
    }
};
