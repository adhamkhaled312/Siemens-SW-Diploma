//https://leetcode.com/problems/number-of-islands/description/
class Solution {
public:

    void discover(const vector<vector<char>>& grid,int row, int col,vector<vector<bool>>& visited){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()  || grid[row][col]=='0' || visited[row][col] ){
            return;
        }
        visited[row][col]=true;
        discover(grid,row,col+1,visited);
        discover(grid,row,col-1,visited);
        discover(grid,row+1,col,visited);
        discover(grid,row-1,col,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited( grid.size(), vector<bool>(grid[0].size(),false));
        int ret=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    discover(grid,i,j,visited);
                    ret++;

                }
            }
        }
        return ret;
    }
};