class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != -1)
                    return "";
                mid = i;
            }
        }

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int m = n / 2;
        auto build = [&](string left) {
            string ans = left;

            if (mid != -1)
                ans += char('a' + mid);

            reverse(left.begin(), left.end());
            ans += left;

            return ans;
        };

        string left;
        vector<int> rem = halfCnt;

        bool equalPossible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                equalPossible = false;
                break;
            }

            left += target[i];
            rem[x]--;
        }

        if (equalPossible) {
            string pal = build(left);

            if (pal > target)
                return pal;
        }


        for (int pos = m - 1; pos >= 0; pos--) {
            rem = halfCnt;
            bool possible = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    possible = false;
                    break;
                }

                rem[x]--;
            }

            if (!possible)
                continue;

            int targetChar = target[pos] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                string candidate = target.substr(0, pos);

                candidate += char('a' + c);
                rem[c]--;

                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        candidate += char('a' + x);
                        rem[x]--;
                    }
                }

                string ans = build(candidate);

                if (ans > target)
                    return ans;
            }
        }

        return "";
    }
};