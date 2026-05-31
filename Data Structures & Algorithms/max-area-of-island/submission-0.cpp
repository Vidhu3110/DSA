class Solution {
public:
    int DFS(int i , int j , int row,int col, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0 || visited[i][j]){
            return 0;
        }
        visited[i][j] = true;
        return 1+ DFS(i-1,j,row,col,visited,grid)+DFS(i+1,j,row,col,visited,grid)+DFS(i,j-1,row,col,visited,grid)+DFS(i,j+1,row,col,visited,grid);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i = 0 ; i< row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(!visited[i][j] && grid[i][j]){
                    maxArea = max(maxArea,DFS(i,j,row,col,visited,grid));
                }
            }
        }
    return maxArea;
    }
};
