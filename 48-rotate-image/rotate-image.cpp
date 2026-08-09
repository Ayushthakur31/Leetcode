class Solution {
public:
//BruteForce
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //    vector<vector<int>> ans(n,vector<int> (n,0));
    //     for(int i = 0;i < n;i++){
    //         for(int j = 0;j < n;j++){
    //             ans[j][(n-1)-i] = matrix[i][j];
    //         }
    //     }
    //     matrix = ans;
    // }

//optimal
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i < n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }    
};