class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int original_color = image[sr][sc];
        int newColor = color;
        if(original_color != newColor)
            DFS(sr,sc,row,col,original_color,newColor,image);

        return image;
    }
    void DFS(int i , int j ,int row , int col , int original_color, int newColor,vector<vector<int>>& image){
        if(i < 0 || i >= row || j < 0 || j >= col || image[i][j]!=original_color){
            return;
        }
        image[i][j] = newColor;
        DFS(i-1,j,row,col,original_color,newColor,image);
        DFS(i+1,j,row,col,original_color,newColor,image);
        DFS(i,j-1,row,col,original_color,newColor,image);
        DFS(i,j+1,row,col,original_color,newColor,image);
    }
};