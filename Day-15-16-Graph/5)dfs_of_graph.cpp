Solution 1-:
Steps-:
1)dfs means going depth of current source.

void dfs(vector<int>adj[],vector<int>&visited,int s,vector<int>&ans)
{
        visited[s]=true;
        ans.push_back(s);
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            dfs(adj,visited,x,ans);
        }
}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>visited(V,false);
        dfs(adj,visited,0,ans);
        return ans;
        
    }


Java -:
void dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int s, ArrayList<Integer> ans) {
        visited[s] = true;
        ans.add(s);

        for (int x : adj.get(s)) {
            if (!visited[x]) {
                dfs(adj, visited, x, ans);
            }
        }
}

public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] visited = new boolean[V];
        dfs(adj, visited, 0, ans);
        return ans;
}


Python Code-:
class Solution:
    
    # Helper function for depth-first search
    def dfs(self, adj, visited, s, ans):
        visited[s] = True
        ans.append(s)
        
        # Traversing all adjacent vertices
        for x in adj[s]:
            if not visited[x]:
                self.dfs(adj, visited, x, ans)
    
    # Function to return a list containing the DFS traversal of the graph
    def dfsOfGraph(self, V, adj):
        ans = []
        visited = [False] * V
        
        # Start DFS from node 0 (or any other node if needed)
        self.dfs(adj, visited, 0, ans)
        return ans