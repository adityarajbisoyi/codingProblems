Solution 1-:
Steps-:
1)if root is null || root is leaf node that is called balanced binary tree.
2)Find height at every step left and right of root node.
3)if(abs(left-right)<=1 and check left side and check right side)


Code-: Time->O(n2)
int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        if(root->left==NULL and root->right==NULL) return 1;
        int left=height(root->left);
        int right=height(root->right);
        return (abs(left-right)<=1 and isBalanced(root->left) and isBalanced(root->right));
    }


Solution 2-:
Steps-:
1)Going from bottom to top because we have to return height also 
2)Intially we make ans=1 if abs(left-right)>1  ans=0;

Code-:
int helper(TreeNode* root,int &res)
{
        if(root==NULL) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);

        if(abs(left-right)>1)
        res=0;
        
        return 1+max(left,right);
}

bool isBalanced(TreeNode* root) {
       int res=1;
       helper(root,res);
       return res;
}


Python Code-:
class Solution:
    def isBalanced(self, root):
        # Helper function to check balance and calculate height
        def helper(node):
            if node is None:
                return 0  # Height of an empty tree is 0

            left_height = helper(node.left)  # Height of left subtree
            right_height = helper(node.right)  # Height of right subtree

            # If either subtree is unbalanced, propagate -1 upwards
            if left_height == -1 or right_height == -1:
                return -1

            # Check if the current subtree is balanced
            if abs(left_height - right_height) > 1:
                return -1  # Tree is unbalanced

            return 1 + max(left_height, right_height)  # Return height of current subtree

        # Start the balance check
        return helper(root) != -1  # If not -1, tree is balanced