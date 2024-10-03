Solution 1-:
Steps-:
1) make a vector v and storing the inorder traversal of both bst in it.
2) sort the vector v.
3) return it.



Solution 2-: 
Steps-:
1)Make a vector v1 and v2.
2)store the inorder traversal in it.
3)As we are storing the inorder of BST it means both v1 and v2 are in sorted order.
4)Now merge both the vectors.

Code-: Time->O(N+M) Space->O(N+M+H1+H2)
void inorder(Node* root,vector<int>&v)
{
       if(root==NULL) return ;
       inorder(root->left,v);
       v.push_back(root->data);
       inorder(root->right,v);
}
    
void merge(vector<int>v1,vector<int>v2,vector<int>&v,int n1,int n2)
{
        int i=0;
        int j=0;
        
        while(i<n1 and j<n2)
        {
            if(v1[i]<=v2[j])
            v.push_back(v1[i++]);
            else
            v.push_back(v2[j++]);
        }
        while(i<n1)
        {
            v.push_back(v1[i++]);
        }
        while(j<n2)
        {
            v.push_back(v2[j++]);
        }
}

vector<int> merge(Node *root1, Node *root2)
{
       vector<int>v1;
       vector<int>v2;
       inorder(root1,v1);
       inorder(root2,v2);
       
       int n1=v1.size();
       int n2=v2.size();
       
       vector<int>v;
       merge(v1,v2,v,n1,n2);
       return v;
}


Python Code-:
class Solution:
    def inorder(self, root, v):
        """Perform inorder traversal and store the result in v."""
        if root is None:
            return
        self.inorder(root.left, v)
        v.append(root.data)  # Use append to add to the list
        self.inorder(root.right, v)

    def merge_sorted_arrays(self, v1, v2):
        """Merge two sorted lists v1 and v2 into a single sorted list."""
        i, j = 0, 0
        merged = []

        # Merge the two lists
        while i < len(v1) and j < len(v2):
            if v1[i] <= v2[j]:
                merged.append(v1[i])
                i += 1
            else:
                merged.append(v2[j])
                j += 1

        # Append remaining elements of v1 if any
        while i < len(v1):
            merged.append(v1[i])
            i += 1

        # Append remaining elements of v2 if any
        while j < len(v2):
            merged.append(v2[j])
            j += 1

        return merged

    def merge(self, root1, root2):
        """Merge two BSTs and return the sorted list of values."""
        v1 = []
        v2 = []
        
        # Perform inorder traversal on both trees
        self.inorder(root1, v1)
        self.inorder(root2, v2)
        
        # Merge the two sorted lists
        return self.merge_sorted_arrays(v1, v2)