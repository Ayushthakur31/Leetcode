class Solution {
public:
// Recursion
//     int f(int n){
//     if (n <= 1)
//         return n;
//     return f(n-1) + f(n-2);
// }    
//     int fib(int n) {
//        return f(n);
//     }

//Memoization
//     int f(int n,vector<int> &dp){
//     if (n <= 1)
//         return n;
//     if(dp[n] != -1) return dp[n];    
//     return f(n-1,dp) + f(n-2,dp);
// }    
//     int fib(int n) {
//         vector<int> dp(n+1,-1);
//        return f(n,dp);
//     }

//Tabulation
//    int fib(int n) {
//          if (n <= 1)
//            return n; 
//         vector<int> dp(n+1,0);
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2;i <= n;i++){  
//            dp[i] = dp[i-1] + dp[i-2];
//         }
//        return dp[n];
//    }

//Space Optimisation
    int fib(int n) {
         if (n <= 1)
           return n; 
        int prev1 = 0;
        int prev2 = 1;
        for(int i = 2;i <= n;i++){  
           int curr = prev1 + prev2;
           prev1 = prev2;
           prev2 = curr;
        }
       return prev2;
   }
};