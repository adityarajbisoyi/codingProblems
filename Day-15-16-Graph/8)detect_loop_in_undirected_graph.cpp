https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0


Solution 1-:
Steps-:
1)here we use dfs and visited array to mark which is used.
2)here we use prev variable and src varible which tells us that src value ka prev value kya ha.
3)if we get prev value!=x (which is (adjacency)value of src) and visited[x]==true 
  it means there is a cycle because x is repeating element.



Code-:
bool dfs(vector<int>adj[],vector<int>&visited,int src,int prev)
{
        visited[src]=true;
        
        for(auto x:adj[src])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,x,src)==true)
                return true;
            }
            else if(visited[x]==true and x!=prev)
            return true;
            else
            continue;
        }
        return false;
}

bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        
        int prev=-1;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,i,prev)==true)
                return true;
            }
        }
        return false;
}


Sol-:2
Steps-:
1)using bfs method.

Code-:
bool bfs(vector<int>adj[],int s,int v,vector<int>&visited)
    {
       queue<int>q;
       q.push(s);
       visited[s]=true;
       vector<int>par(v,-1);
       
       while(q.empty()==false)
       {
           int val=q.front();
           q.pop();
           
           for(auto x:adj[val])
           {
               if(visited[x]==false)
               {
                   visited[x]=true;
                   q.push(x);
                   par[x]=val;
               }
               else if(x!=par[val])
               return true;
               else
               continue;
           }
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        int par=-1;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(bfs(adj,i,V,visited)==true)
                return true;
            }
        }
        return false;
    }


Python Code-:

def isCycleUtil(self, u, par, adj, vis):
        
        #marking the current vertex as visited.
        vis[u] = True
        
        #iterating on all the adjacent vertices.
        for v in adj[u]:
            
            if(v == par):
                continue
            
            #if current vertex is visited, we return true else we 
			#call the function recursively to detect the cycle.
            elif(vis[v]):
                return True
            else:
                if(self.isCycleUtil(v, u, adj, vis)):
                    return True
        return False
        
    #Function to detect cycle in an undirected graph.
    def isCycle(self, V, adj):
        
        #using a boolean list to mark all the vertices as not visited.
        vis = [False for i in range(V)]
        
        #iterating over all the vertices.
        for i in range(V):
            
            #if vertex is not visited, we call the function to detect cycle.
            if(vis[i] == False):
                
                #if cycle is found, we return true.
                if(self.isCycleUtil(i, -1, adj, vis)):
                    return True
        return False