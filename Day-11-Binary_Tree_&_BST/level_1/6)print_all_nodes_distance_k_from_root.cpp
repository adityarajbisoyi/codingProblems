Question link-:
https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

Solution 1-:

Code-:
void helper(Node* root,int k,vector<int>&v,int dist)
{
    if(root==NULL)
    return ;
    
    if(dist==k)
    {
        v.push_back(root->data);
        return ;
    }
    helper(root->left,k,v,dist+1);
    helper(root->right,k,v,dist+1);
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int>v;
    int dist=0;
    helper(root,k,v,dist);
    return v;
}

Python Code-:
class Solution:
    def KDistance(self, root, k):
        # List to store the nodes at distance k
        result = []
        
        # Helper function for traversal
        def helper(node, dist):
            if node is None:
                return
            
            if dist == k:
                result.append(node.data)
                return
            
            # Recurse for left and right children
            helper(node.left, dist + 1)
            helper(node.right, dist + 1)
        
        # Start the helper function with initial distance 0
        helper(root, 0)
        
        return result