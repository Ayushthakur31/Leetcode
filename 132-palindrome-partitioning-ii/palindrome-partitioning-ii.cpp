class Solution {
public:
//recursive
//    bool palindrome(int i,int j,string &s){
//     while(i < j){
//         if(s[i] != s[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
//    }
   
//    int f(int i,string &s){
//     if(i == s.size()) return 0;
//     int mini = 1e9;
//     for(int j = i;j < s.size();j++){
//         if(palindrome(i,j,s)){
//             mini = min(mini, 1+ f(j+1,s));
//         }
//     }
//     return mini;
//    }
//     int minCut(string s) {
//         return f(0,s) - 1;
//     }

//memoization
    bool palindrome(int i,int j,string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
   }
   
   int f(int i,string &s,vector<int> &dp){
    if(i == s.size()) return 0;
    if(dp[i] != -1) return dp[i];
    int mini = 1e9;
    for(int j = i;j < s.size();j++){
        if(palindrome(i,j,s)){
            mini = min(mini, 1+ f(j+1,s,dp));
        }
    }
    return dp[i] = mini;
   }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return f(0,s,dp) - 1;
    }
};