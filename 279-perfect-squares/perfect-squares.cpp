class Solution {
public:
//Recursion
    // int f(int n){
    //     if(n == 0) return 0;
    //     int ans = 1e9;

    //     for(int i = 1;i * i <= n;i++){
    //         int square = i*i;
    //         ans = min(ans, 1+f(n - square));
    //     }
    //     return ans;
    // }
    // int numSquares(int n) {
    //     return f(n);
    // }

//Memoisation
    // int f(int n,vector<int>& dp){
    //     if(n == 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int ans = 1e9;

    //     for(int i = 1;i * i <= n;i++){
    //         int square = i*i;
    //         ans = min(ans, 1+f(n - square,dp));
    //     }
    //     return dp[n] = ans;
    // }
    // int numSquares(int n) {
    //     vector<int> dp(n+1,-1);
    //     return f(n,dp);
    // }  

//Tabulation
    int numSquares(int n) {
        vector<int> dp(n+1,0);
          dp[0] = 0;
        for(int i = 1;i <= n;i++){
        int ans = 1e9;

        for(int j = 1;j * j <= i;j++){
            int square = j*j;
            ans = min(ans, 1+dp[i - square]);
        }
          dp[i] = ans;
        }
        return dp[n];
    }      
};