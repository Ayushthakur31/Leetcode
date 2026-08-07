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
    int f(int n,vector<int> &dp){
    if (n <= 1)
        return n;
    if(dp[n] != -1) return dp[n];    
    return f(n-1,dp) + f(n-2,dp);
}    
    int fib(int n) {
        vector<int> dp(n+1,-1);
       return f(n,dp);
    }
};