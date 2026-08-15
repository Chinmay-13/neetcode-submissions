class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {

                if (!dfs(neighbor, node, adj, visited))
                    return false;
            }
            else if (neighbor != parent) {
                // Visited node that isn't our parent = cycle
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Check for cycle
        if (!dfs(0, -1, adj, visited))
            return false;

        // Check connectivity
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};