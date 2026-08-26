class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int left = 0, ones = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            
            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }
            
            if (ones == k) {
                int l = left;
                while (s[l] == '0') l++;
                
                string candidate = s.substr(l, right - l + 1);
                
                if (best.empty() || candidate.size() < best.size() ||
                    (candidate.size() == best.size() && candidate < best)) {
                    best = candidate;
                }
            }
        }
        
        return best;
    }
};