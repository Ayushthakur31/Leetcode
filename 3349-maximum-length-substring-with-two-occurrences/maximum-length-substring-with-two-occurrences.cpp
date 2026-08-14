class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mpp;
        
        int left = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {
            mpp[s[right]]++;

            while (mpp[s[right]] > 2) {
                mpp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};