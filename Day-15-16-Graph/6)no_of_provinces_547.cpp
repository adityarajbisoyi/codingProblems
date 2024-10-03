https://leetcode.com/problems/number-of-provinces/description/

Solution 1-:
Steps-:
1)here we have to calculate the no. of connected graph 
2)Make a adj list and count no. of connected graph.

Code-:
void dfs(vector<int>&visited,vector<int>adj[],int s)
{
        visited[s]=true;
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            dfs(visited,adj,x);
        }
}

int findCircleNum(vector<vector<int>>&adj) {
        int V=adj.size();
        vector<int>ad[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                ad[i].push_back(j);
            }
        }
        
        vector<int>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(visited,ad,i);
            }
        }
        return count;
}


[1,0,0,1]
[0,1,1,0]
[0,1,1,1]
[1,0,1,1]

Solution 2-:
Steps-:
1)Simply using same vector of vector.
2)Traverse using vector of vector.

Code-:
void dfs(vector<vector<int>>&mat,int s,int v,vector<int>&visited)
{
        visited[s]=true;

        for(int i=0;i<v;i++)
        {
            if(i!=s and mat[s][i]==1 and visited[i]==false)
            dfs(mat,i,v,visited);
        }
}

int findCircleNum(vector<vector<int>>& isConnected) 
{
        int v=isConnected.size();

        vector<int>visited(v,false);
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(isConnected,i,v,visited);
            }
        }
        return count;
}


Python Code-:
class Solution(object):
    def dfs(self, isConnected, visited, i):
        # Mark the current node as visited
        visited[i] = True
        
        # Visit all adjacent nodes (i.e., nodes that are directly connected)
        for j in range(len(isConnected)):
            if isConnected[i][j] == 1 and not visited[j]:
                self.dfs(isConnected, visited, j)

    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        # Number of nodes (cities or provinces)
        n = len(isConnected)
        
        # Track visited nodes
        visited = [False] * n
        
        # Count of connected components (or provinces)
        count = 0
        
        # Traverse each node
        for i in range(n):
            if not visited[i]:
                # Start a DFS to visit all nodes in the current component
                self.dfs(isConnected, visited, i)
                # Increment the count of provinces
                count += 1
                
        return count