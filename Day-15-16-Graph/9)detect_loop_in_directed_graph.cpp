Solution 1-:
Steps-:
1)using dfs 
2)here the graph may be of 2-3 breakage will be there.
3)visited[array] is used to check whelter paticipular is used or not as we used in undirected question.
4)reckracnce array is used to put the element update for current graph like 2nd part not 1st part.
4)now if we have 2 disconnected graph -:
  1st graph -> suppose there is no loop.
  so we make visited array same but rec[array]=false.

0->1<-2   in undirected graph logic shows there is a cycle.
but here in directed graph its not.


0->1<-2->3->4->5->3

Code-:
bool dfs(vector<int>adj[],vector<int>&visited,vector<int>&rec,int s)
{
        visited[s]=true;
        rec[s]=true;
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,rec,x)==true)
                return true;
            }
            else if(rec[x]==true)
            return true;
            else
            continue;
        }
        rec[s]=false;
        return false;
}

bool isCyclic(int V, vector<int> adj[]) 
{
        vector<int>visited(V,false);
        vector<int>rec(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,rec,i)==true)
                return true;
            }
        }
        return false;
}


Python Code-:
class Solution:

    def DFSUtil(self, adj, v, visited, recStack):

        #marking the current node as visited and part of recursion stack.
        visited[v] = True
        recStack[v] = True

        #calling function recursively for all neighbours
        #if any neighbour is visited and is in recStack then graph is cyclic.
        for neighbour in adj[v]:
            if visited[neighbour] == False:
                if self.DFSUtil(adj, neighbour, visited, recStack) == True:
                    return True
            elif recStack[neighbour] == True:
                return True

        #removing the vertex from recursion stack.
        recStack[v] = False
        return False

    #Function to detect cycle in a directed graph.
    def isCyclic(self, V, adj):

        #marking all vertices as not visited and not a part of recursion stack
        visited = [False] * V
        recStack = [False] * V

        #calling the recursive helper function to detect cycle in
        #different DFS trees.
        for node in range(V):
            if visited[node] == False:
                if self.DFSUtil(adj, node, visited, recStack) == True:
                    return True
        return False