class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {
                int bigger = -1;

                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != -1) {
                    ans += char('a' + bigger);
                    freq[bigger]--;

                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }

                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) {

            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = ans.substr(0, i);

                    result += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};