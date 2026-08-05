class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int node) {
        vis[node] = 1;
        for (int nxt : adj[node]) {
            if (!vis[nxt])
                dfs(nxt);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        adj.resize(n);
        vis.assign(n, 0);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        dfs(k);

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};