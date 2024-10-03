Inorder traversal is ->left,root,right.

Solution 1-:
using recursion

Code-: Time->O(N)
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        
        v.push_back(root->data);
    
        helper(root->right,v);
}

vector<int> inOrder(Node* root) {
      vector<int>v;
      helper(root,v);
      return v;
}


Python Code-:
class Solution:
    def helper(self, root, v):
        if root is None:
            return
        # Traverse left subtree
        self.helper(root.left, v)
        # Add root data to the list
        v.append(root.data)  # Use 'data' instead of 'key'
        # Traverse right subtree
        self.helper(root.right, v)

    def InOrder(self, root):
        # List to store the result
        v = []
        # Call helper to fill the list with in-order traversal
        self.helper(root, v)
        # Return the result
        return v