Code-:
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       vector<int>dist(V,1e8);
       dist[S]=0;
       for(int i=0;i<V-1;i++)
       {
           for(auto x:edges)
           {
               int u=x[0];
               int v=x[1];
               int wt=x[2];
               if(dist[u]!=1e8 and dist[v]>dist[u]+wt)
               dist[v]=dist[u]+wt;
           }
       }
       
       // nth iteration check
       for(auto x:edges)
       {
           int u=x[0];
           int v=x[1];
           int wt=x[2];
           if(dist[u]!=1e8 and dist[v]>dist[u]+wt)
           return {-1};
       }
       return dist;
    }

Python Code-:
class Solution:
    # Function to find the shortest distance of all vertices from the source vertex S using Bellman-Ford algorithm
    def bellman_ford(self, V, edges, S):
        # Initialize distances to all vertices as a large value (1e8 or 100000000)
        dist = [100000000] * V
        # Distance to the source is 0
        dist[S] = 0

        # Relax all edges (V - 1) times
        for i in range(V - 1):
            for u, v, wt in edges:
                if dist[u] != 100000000 and dist[v] > dist[u] + wt:
                    dist[v] = dist[u] + wt

        # Check for negative weight cycle (Nth iteration)
        for u, v, wt in edges:
            if dist[u] != 100000000 and dist[v] > dist[u] + wt:
                # If we can relax further, a negative weight cycle exists
                return [-1]

        # Return the distances array if no negative weight cycle exists
        return dist
