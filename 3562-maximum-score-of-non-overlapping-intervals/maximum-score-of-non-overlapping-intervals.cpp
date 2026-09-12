class Solution {
public:

    struct Node {
        int l, r, w, idx;
    };

    vector<Node> a;
    vector<int> starts;

    struct State {
        long long score;
        vector<int> ids;
    };

    vector<vector<State>> dp;
    vector<vector<bool>> vis;

    bool smaller(vector<int>& x, vector<int>& y) {
        return x < y;   // vector gives lexicographical comparison
    }

    State solve(int i, int k) {

        if (i >= a.size() || k == 0)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        // Skip
        State skip = solve(i + 1, k);

        // Take
        int nxt = upper_bound(
            starts.begin(),
            starts.end(),
            a[i].r
        ) - starts.begin();

        State nxtState = solve(nxt, k - 1);

        State take;

        take.score = a[i].w + nxtState.score;

        take.ids = nxtState.ids;
        take.ids.push_back(a[i].idx);

        // Sort original indices
        sort(take.ids.begin(), take.ids.end());

        // Choose better
        if (take.score > skip.score) {
            dp[i][k] = take;
        }
        else if (take.score < skip.score) {
            dp[i][k] = skip;
        }
        else {
            if (take.ids < skip.ids)
                dp[i][k] = take;
            else
                dp[i][k] = skip;
        }

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.reserve(n);

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](Node& x, Node& y) {
            if (x.l != y.l)
                return x.l < y.l;

            return x.r < y.r;
        });

        starts.resize(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i].l;

        dp.resize(n + 1, vector<State>(5));
        vis.resize(n + 1, vector<bool>(5, false));

        return solve(0, 4).ids;
    }
};