class Solution {
public:
    void f(string& seq, int ind, int depth, vector<int>& ans) {
        if (ind == seq.size())
            return;

        if (seq[ind] == '(') {
            depth++;
            ans[ind] = depth % 2;
        }
        else {
            ans[ind] = depth % 2;
            depth--;
        }

        f(seq, ind + 1, depth, ans);
    }

    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);

        f(seq, 0, 0, ans);

        return ans;
    }
};