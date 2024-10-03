Solution 1-:


Code-:
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;

    
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL and right==NULL) return NULL;
        if(left!=NULL and right!=NULL) return root;
         
        return (left!=NULL)?left:right;
    }


Python Code-:
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        # Base case: if the root is None, return None
        if root is None:
            return None
        
        # If either p or q is the root, then root is LCA
        if root == p or root == q:
            return root

        # Recursively search in the left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)  # Search in left subtree
        right = self.lowestCommonAncestor(root.right, p, q)  # Search in right subtree

        # If both left and right are not None, then root is LCA
        if left is not None and right is not None:
            return root
        
        # Otherwise, return the non-None child (left or right)
        return left if left is not None else right