

void shortest_distance(vector<vector<int>>&matrix)
{
	    int n=matrix.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	        }
	    }  
	    
	    for(int k=0;k<n;k++)
	    {
	       for(int i=0;i<n;i++)
	       {
	         for(int j=0;j<n;j++)
	         {
	            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	         }
	       } 
	    }
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            matrix[i][j]=-1;
	        }
	    }
}


Python Code-:
class Solution:
    def shortest_distance(self, matrix):
        n = len(matrix)
        
        # Step 1: Replace -1 with a large value (1e9) to represent infinity for unreachable paths
        for i in range(n):
            for j in range(n):
                if matrix[i][j] == -1:
                    matrix[i][j] = 10**9

        # Step 2: Floyd-Warshall algorithm to compute shortest distances between all pairs
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

        # Step 3: Replace large values (1e9) back to -1 to signify unreachable paths
        for i in range(n):
            for j in range(n):
                if matrix[i][j] == 10**9:
                    matrix[i][j] = -1
