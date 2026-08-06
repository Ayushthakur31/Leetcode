class Solution {
public:
//recursion
    // int f(int n){
    //     if(n <= 2) return n;
    //     return f(n-1) + f(n-2);
    // }
    // int climbStairs(int n) {
    //     return f(n);
    // }

//Memoization
    //  int f(int n,vector<int> &dp){
    //     if(n <= 2) return n;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = f(n-1,dp) + f(n-2,dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return f(n,dp);
    // }

//Tabulation
    // int climbStairs(int n) {
    //     if(n <= 2) return n;
    //     vector<int> dp(n+1,0);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for(int i = 3;i <= n;i++){
    //          dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }    

//Space Optimisation
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1;
        int prev1 = 2;
        for(int i = 3;i <= n;i++){
             int curr = prev1 + prev2;
             prev2 = prev1;
             prev1 = curr;
        }
        return prev1;
    }        
};