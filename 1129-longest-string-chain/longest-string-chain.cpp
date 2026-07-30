class Solution {
public:
    bool check(string &s1,string &s2){
        if(s1.size() + 1 != s2.size()) return false;
            int i = 0,j = 0;
            while(j < s2.size()){
                if(i < s1.size() && s1[i] == s2[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            return i == s1.size();
        }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size() < b.size();
        });
        int n = words.size();
         vector<int> dp(n, 1);
    int maxi = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (check(words[prev] ,words[i]) && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;
            }
        }

        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }
        return maxi;
    }
};