Solution 1-:

Code-: Time->O(n)
int maxDepth(TreeNode* root) 
{
        if(root==NULL)
        return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
}


Python Code-:
class Solution:
    # Function to find the height of a binary tree.
    def height(self, root):
        if root is None:
            return 0
        # Calculate the height of left and right subtrees and return the maximum
        return 1 + max(self.height(root.left), self.height(root.right))
