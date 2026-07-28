class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n/2;
        sort(s.begin(),s.begin()+mid);
        for(int i = 0;i < n/2;i++){
            s[n-i-1] = s[i];
        }
        return s;
    }
};