#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int x)
    {
        left=NULL;
        right=NULL;
        key=x;
    }
};

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    printall(root);
    return 0;
}


Python Code-:
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Function to print all nodes in a simple way
def printall(root):
    if root is not None:
        print(root.key, end=" ")  # Print root node
        printall(root.left)       # Recursively print left subtree
        printall(root.right)      # Recursively print right subtree

if __name__ == "__main__":
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    printall(root)
