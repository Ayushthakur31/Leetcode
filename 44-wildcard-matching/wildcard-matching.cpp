class Solution {
public:
    // int f(int i,int j,string &s,string &p){
    //     if(i < 0 && j < 0) return true;
    //     if(j < 0 && i >= 0) return false;
    //     if(i < 0 && j >= 0){
    //         for(int k = 0;k <= j;k++){
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(s[i] == p[j] || p[j] == '?')
    //         return f(i-1,j-1,s,p);
    //     if(p[j] == '*')
    //         return f(i-1,j,s,p) || f(i,j-1,s,p);
    //     return false;        
    // }
    // bool isMatch(string s, string p) {
    //    int n = s.size();
    //    int m = p.size();
    //    return f(n-1,m-1,s,p);
    // }

    //Memoization
    //  int f(int i,int j,string &s,string &p,vector<vector<int>> &dp){
    //     if(i < 0 && j < 0) return true;
    //     if(j < 0 && i >= 0) return false;
    //     if(i < 0 && j >= 0){
    //         for(int k = 0;k <= j;k++){
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == p[j] || p[j] == '?')
    //         return dp[i][j] = f(i-1,j-1,s,p,dp);
    //     if(p[j] == '*')
    //         return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
    //     return dp[i][j] = false;        
    // }
    //  bool isMatch(string s, string p) {
    //    int n = s.size();
    //    int m = p.size();
    //    vector<vector<int>> dp(n,vector<int>(m,-1));
    //    return f(n-1,m-1,s,p,dp);
    //  }

    // Tabulation
    //   bool isMatch(string s, string p) {
    //    int n = s.size();
    //    int m = p.size();
    //    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    //    dp[0][0] = true;
    //    for (int j = 1; j <= m; j++) {
    //         if (p[j - 1] == '*')
    //             dp[0][j] = dp[0][j - 1];
    //     }
    //    for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++){
    //     if(s[i-1] == p[j-1] || p[j-1] == '?')
    //          dp[i][j] = dp[i-1][j-1];
    //     else if(p[j-1] == '*')
    //          dp[i][j] = dp[i-1][j] || dp[i][j-1];
    //     else{
    //         dp[i][j] = false;
    //     }
    //     }
    //   }
    //     return dp[n][m];
    //  }

    // Space optimization
    bool isMatch(string s, string p) {
       int n = s.size();
       int m = p.size();
       vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
        prev[0] = true;
       for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }
       for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            curr[0] = false;
        if(s[i-1] == p[j-1] || p[j-1] == '?')
             curr[j] = prev[j-1];
        else if(p[j-1] == '*')
             curr[j] = prev[j] || curr[j-1];
        else{
            curr[j] = false;
        }
        }
        prev = curr;
      }
        return prev[m];
     }
};