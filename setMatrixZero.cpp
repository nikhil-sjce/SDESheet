class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int cols = 1, rows = matrix.size(), columns = matrix[0].size();
        for(int i=0;i<rows;i++){
            if(matrix[i][0] == 0)
                cols = 0;
            for(int j=1;j<columns;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = rows-1;i>=0;i--){
            for(int j=columns-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(cols == 0)
                matrix[i][0] = 0;
        }
    /////////////////////////////
    //    
    //     Method 2 O(M+N) Space
    //     vector<int>r(matrix.size(), -1);
    //     vector<int>c(matrix[0].size(), -1);
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();
    //     for(int i=0;i<rows;i++){
    //         for(int j=0;j<cols;j++){
    //             if(matrix[i][j] == 0){
    //                 r[i] = 0;
    //                 c[j] = 0;
    //             }
    //         }
    //     }
    //     for(int i=0;i<rows;i++){
    //         for(int j=0;j<cols;j++){
    //             if(r[i]==0 || c[j]==0)
    //                 matrix[i][j] = 0;
    //         }
    //     }
    // }
};