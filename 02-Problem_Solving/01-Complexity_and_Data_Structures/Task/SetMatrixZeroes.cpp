//Problem link:https://leetcode.com/problems/set-matrix-zeroes/submissions/1340681655/
//Submission link:https://leetcode.com/submissions/detail/1340681655/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        unordered_set<int>rows;
        unordered_set<int>columns;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(auto it : columns){
            for(int i=0;i<rowSize;i++){
                matrix[i][it]=0;
            }
        }
        for(auto it : rows){
            for(int i=0;i<colSize;i++){
                matrix[it][i]=0;
            }
        }
    }
};
int main(){}