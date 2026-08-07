class Solution {
public:
//Recursion
// int f(int n){
//     if(n == 0) return 0;
//     if(n == 1 || n == 2) return 1;
//     return  f(n-1) + f(n-2) + f(n-3);
// }
//     int tribonacci(int n) {
//         return f(n);
//     }

//Memoisation
//     int f(int n,vector<int>& dp){
//     if(n == 0) return 0;
//     if(n == 1 || n == 2) return 1;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] =  f(n-1,dp) + f(n-2,dp) + f(n-3,dp);
// }
//     int tribonacci(int n) {
//         vector<int> dp(n+1,-1);
//         return f(n,dp);
//     }

//Tabulation
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i <= n;i++){
           dp[i] =  dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }    
};