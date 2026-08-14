class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited){
        visited[i] = 1;

        for(int neigh : adj[i]){
            if(!visited[neigh]){
                dfs(neigh,adj,visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];

            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        vector<int> visited(n,0);
        int components = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                dfs(i,adj,visited);
            }
        }
        return components;
    }
};
