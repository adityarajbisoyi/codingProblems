Question ->we have to find the min and max element in binary TreeNode

Question link-:
https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

Solution 1-:
Steps-:
Using recursion

Code-:
    int findMax(Node *root)
    {
        if(root==NULL) return INT_MIN;
        return max(root->data,max(findMax(root->left),findMax(root->right)));
    }
    int findMin(Node *root)
    {
        if(root==NULL) return INT_MAX;
        return min(root->data,min(findMin(root->left),findMin(root->right)));
    }


Python Code-:
class Solution:
    # Function to find the maximum value in a binary tree.
    def findMax(self, root):
        if root is None:
            return float('-inf')  # Using negative infinity for the minimum comparison
        return max(root.data, max(self.findMax(root.left), self.findMax(root.right)))

    # Function to find the minimum value in a binary tree.
    def findMin(self, root):
        if root is None:
            return float('inf')  # Using positive infinity for the maximum comparison
        return min(root.data, min(self.findMin(root.left), self.findMin(root.right)))

