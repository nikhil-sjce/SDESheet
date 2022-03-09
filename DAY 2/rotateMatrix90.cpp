// METHOD 1 : CLOCKWISE
for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            swap(mat[i][j], mat[j][i]);
    }
    for(int i=0;i<n;i++)
        reverse(mat[i].begin(), mat[i].end());

// METHOD 2 : ANTICLOCKWISE
void rotate(vector<vector<int> >& mat){
    int n = mat.size(), m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    reverse(mat.begin(), mat.end());
}