class Solution {
public:
    bool isVowel(char c) {
    c = tolower(c);

    return c == 'a' || c == 'e' || c == 'i' || 
           c == 'o' || c == 'u';
}
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i < k;i++){
            if(isVowel(s[i])) cnt++;
        }
        int maxi = cnt;
        for(int i = k;i < n;i++){
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i-k])) cnt--;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }    
};