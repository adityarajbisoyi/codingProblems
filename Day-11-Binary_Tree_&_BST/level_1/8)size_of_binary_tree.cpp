Solution 1-:
idea-:
Just add the root +left_side+right_side


using recursion
Code-: Time->O(n)
int countNodes(TreeNode* root) 
{
        if(root==NULL)
        return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
}


Solution 2-:
Using level order traversal

Code-:
 int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(q.empty()==false)
        {
            count++;
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        return count;
}


Python Code-:
class Solution:
    # Function to count the number of nodes in a binary tree.
    def countNodes(self, root):
        if root is None:
            return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)