class Solution {
public:
//recursion
    // int f(int i,int j,vector<int> &piles){
    //     if(i == j) return piles[i];
    //     int left = piles[i] - f(i+1,j,piles);
    //     int right = piles[j] - f(i,j-1,piles);
    //     return max(left,right);
    // }
    // bool stoneGame(vector<int>& piles) {
    //     int n = piles.size();
    //     return f(0,n-1,piles);
    // }

//Memoization
    // int f(int i,int j,vector<int> &piles,vector<vector<int>> &dp){
    //     if(i == j) return piles[i];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int left = piles[i] - f(i+1,j,piles,dp);
    //     int right = piles[j] - f(i,j-1,piles,dp);
    //     return max(left,right);
    // }
    // bool stoneGame(vector<int>& piles) {
    //     int n = piles.size();
    //     vector<vector<int>> dp(n,vector<int> (n,-1));
    //     return f(0,n-1,piles,dp);
    // }    

//Tabulation
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i = 0;i < n;i++) dp[i][i] = piles[i];
        for(int i = n-2;i >= 0;i--){
            for(int j = i+1;j < n;j++){
               int left = piles[i] - dp[i+1][j];
               int right = piles[j] - dp[i][j-1];
               dp[i][j] = max(left,right);
            }
        }
        return dp[0][n-1];
    }       
};