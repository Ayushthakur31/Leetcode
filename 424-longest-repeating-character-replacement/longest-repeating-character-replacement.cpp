class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mpp;
        int n = s.size();
        int l = 0,r = 0,maxlen = 0;
        int maxfreq = 0;
        while(r < n){
        mpp[s[r]] ++;
        maxfreq = max(maxfreq,mpp[s[r]]);
        while(r-l+1 - maxfreq > k){
            mpp[s[l]]--;
            l++;
        }
        int len = r-l+1;
        maxlen = max(maxlen,len);
        r++;
    }
        return maxlen;
    }
};