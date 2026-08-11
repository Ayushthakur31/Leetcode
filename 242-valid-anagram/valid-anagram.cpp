class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size() != t.size()) return false;
       unordered_map<char,int> mpp;
       for(auto c : s){
         mpp[c] ++;
       }
       for(auto c : t){
        if(mpp[c] == 0) return false;
        mpp[c]--;
       }
       return true;
    }
};