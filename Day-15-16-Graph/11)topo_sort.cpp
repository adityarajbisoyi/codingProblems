https://www.geeksforgeeks.org/problems/topological-sort/1


Note -: topoSort is only for acyclic graph 
        if there is a cycle so we cannot find the topological sort.


1)Test case -:
0->1 
0->2 

o/p ->0 1 2 or 0 2 1

2)
0->2 0->3
1->3 1->4 

o/p -> 0 1 2 3 4 



Steps-:
1)Store inDegree of every vertex.
2)Create a queue q.
3)All all 0 degree vertex to the queue.
4)While(q.empty)
{
    a) val=q.front()
    b) print val.
    c) for every adj x of val 
       1)inDegree[x]--;
       2)if inDegree[x]==0
         add x to the queue.
}


Code-: O(V+E)
vector<int> topoSort(int V, vector<int> adj[]) 
{
	   vector<int>v;
	   vector<int>inDegree(V,0);
	   
	   for(int i=0;i<V;i++)
	   {
	       for(auto x:adj[i])
	       {
	           inDegree[x]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(inDegree[i]==0)
	       q.push(i);
	   }
	   
	   while(q.empty()==false)
	   {
	       int val=q.front();
	       q.pop();
	       
	       v.push_back(val);
	       
	       for(auto x:adj[val])
	       {
	           inDegree[x]--;
	           if(inDegree[x]==0)
	           q.push(x);
	       }
	   }
	   return v;
}


Python Code-:
from typing import List
from collections import deque

class Solution:
    # Function to return list containing vertices in Topological order.
    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        # Vector to store the in-degree of each vertex
        inDegree = [0] * V
        
        # Calculate in-degrees for each vertex
        for i in range(V):
            for neighbor in adj[i]:
                inDegree[neighbor] += 1
        
        # Queue for processing vertices with in-degree of 0
        q = deque()
        
        # Enqueue all vertices with in-degree 0
        for i in range(V):
            if inDegree[i] == 0:
                q.append(i)
        
        # List to store the topological order
        topo_order = []
        
        # Process vertices until the queue is empty
        while q:
            current_vertex = q.popleft()  # Dequeue a vertex
            topo_order.append(current_vertex)  # Add to the topological order
            
            # Decrease the in-degree of neighboring vertices
            for neighbor in adj[current_vertex]:
                inDegree[neighbor] -= 1
                # If in-degree becomes 0, enqueue the vertex
                if inDegree[neighbor] == 0:
                    q.append(neighbor)
        
        return topo_order