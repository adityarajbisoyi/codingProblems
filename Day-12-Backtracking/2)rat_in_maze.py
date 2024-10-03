 void helper(vector<vector<int>>&mat,int n,int i,int j,string curr,
                vector<vector<int>>&visited,vector<string>&ans)
    {
        if(i<0 || i==n || j<0 || j==n || mat[i][j]==0) 
        return ;
    
        if(i==n-1 and j==n-1)
        {
            ans.push_back(curr);
            return ;
        }
        
        if(visited[i][j]==0)
        {
             visited[i][j]=1;
             helper(mat,n,i-1,j,curr+"U",visited,ans);
             helper(mat,n,i+1,j,curr+"D",visited,ans);
             helper(mat,n,i,j-1,curr+"L",visited,ans);
             helper(mat,n,i,j+1,curr+"R",visited,ans);
             visited[i][j]=0;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        int n=mat.size();
        int i=0;
        int j=0;
        string curr="";
        vector<vector<int>>visited(n,vector<int>(n,0));
        helper(mat,n,i,j,curr,visited,ans);
        return ans;
    }


Python -:
def helper(mat, n, i, j, curr, visited, ans):
    # Check boundary conditions and if the current cell is blocked (mat[i][j] == 0)
    if i < 0 or i == n or j < 0 or j == n or mat[i][j] == 0:
        return
    
    # If the destination is reached, add the current path to ans
    if i == n - 1 and j == n - 1:
        ans.append(curr)
        return
    
    # If the current cell is not visited
    if visited[i][j] == 0:
        visited[i][j] = 1  # Mark the current cell as visited
        
        # Move up
        helper(mat, n, i - 1, j, curr + "U", visited, ans)
        # Move down
        helper(mat, n, i + 1, j, curr + "D", visited, ans)
        # Move left
        helper(mat, n, i, j - 1, curr + "L", visited, ans)
        # Move right
        helper(mat, n, i, j + 1, curr + "R", visited, ans)
        
        visited[i][j] = 0  # Unmark the current cell (backtracking)
    return

def findPath(mat):
    ans = []
    n = len(mat)
    i = 0
    j = 0
    curr = ""
    visited = [[0 for _ in range(n)] for _ in range(n)]  # Create the visited matrix
    helper(mat, n, i, j, curr, visited, ans)
    return ans