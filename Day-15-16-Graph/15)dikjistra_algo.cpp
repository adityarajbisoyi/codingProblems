Note -:
1)Its not working for -ve weight edges.
2) path change when all extra weight to all the edges.
Code-:
time complexity -> O(Elog(V)) E -> No. of edges. and V is the no. of vertex



Code-:
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
       vector<int>dist(V,1e9);
       dist[S]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,
                      greater<pair<int,int>>>pq;
       pq.push({0,S});
       while(pq.empty()==false)
       {
           int dis=pq.top().first;
           int node=pq.top().second;
           pq.pop();
           
           for(auto x:adj[node])
           {
               int adjNode=x[0];
               int wt=x[1];
               if(dist[adjNode]>dist[node]+wt)
               {
                   dist[adjNode]=dist[node]+wt;
                   pq.push({dist[adjNode],adjNode});
               }
           }
       }
       return dist;
}


Python Code-:
from typing import List
import heapq

class Solution:
    # Function to find the shortest distance of all the vertices from the source vertex S.
    def dijkstra(self, V: int, adj: List[List[int]], S: int) -> List[int]:
        dist = [float('inf')] * V  # Initialize distances to infinity
        dist[S] = 0  # Distance to the source vertex is 0
        pq = []  # Priority queue (min-heap)
        heapq.heappush(pq, (0, S))  # Push source vertex with distance 0

        # Main loop of Dijkstra's algorithm
        while pq:
            dis, node = heapq.heappop(pq)  # Get node with smallest distance

            # Traverse all adjacent nodes
            for x in adj[node]:
                adjNode = x[0]
                wt = x[1]

                # Relaxation step
                if dist[adjNode] > dist[node] + wt:
                    dist[adjNode] = dist[node] + wt
                    heapq.heappush(pq, (dist[adjNode], adjNode))  # Push updated distance into priority queue

        return dist
