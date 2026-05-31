class Solution {
public:
    void DFS(int i,int j,int rows,int cols,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        if(i < 0 || i >= rows || j < 0 || j>= cols || grid[i][j] == '0'){
            return;
        }
        if(!visited[i][j]){
            visited[i][j] = true;
            DFS(i-1,j,rows,cols,visited,grid);
            DFS(i+1,j,rows,cols,visited,grid);
            DFS(i,j-1,rows,cols,visited,grid);
            DFS(i,j+1,rows,cols,visited,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows , vector<bool>(cols,false));
        for(int i = 0; i < rows ; i++){
            for(int j = 0; j<cols;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    DFS(i,j,rows,cols,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
    
};
