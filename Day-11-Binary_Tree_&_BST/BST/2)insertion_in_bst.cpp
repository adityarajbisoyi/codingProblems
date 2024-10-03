C++
Node* insert(Node* node, int data)
{
          if(node==NULL)
          return new Node(data);
          if(node->data==data)
          return root;
          if(root->data<data)
          node->right=insert(node->right,data);
          else
          node->left=insert(node->left,data);
          return node;
}


Java-:
Node insert(Node root, int Key) {
        if(root==null) return new Node(Key);
        if(root.data==Key) return root;
        if(root.data<Key)
        root.right=insert(root.right,Key);
        else
        root.left=insert(root.left,Key);
        return root;
}


Python Code-:

class Solution:
    # Function to insert a node in a BST.
    def insert(self, root, key):
        # If the tree is empty, return a new node
        if root is None:
            return Node(key)
        
        # If the key is already present, return the root (no duplicates)
        if key == root.data:
            return root
        
        # Otherwise, recur down the tree
        if key < root.data:
            root.left = self.insert(root.left, key)  # Insert in the left subtree
        else:
            root.right = self.insert(root.right, key)  # Insert in the right subtree

        return root  # Return the unchanged root pointer
