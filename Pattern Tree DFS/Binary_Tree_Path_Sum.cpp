#include "codeblock.h"

bool hasPath (TreeNode *root, int sum){
    if(root == NULL){
        return false;
    }
    
    if(root->left == NULL && root->right == NULL && sum == root->val){
        return true;
    }
    sum = sum - root->val; 
    return hasPath(root->left, sum) || hasPath(root->right, sum);
}

int main(){
    TreeNode *root = getSampleTree();
    int sum;
    cout << "Enter Sum : ";
    cin >> sum;
    cout << hasPath(root, sum)? "True": "False";

    return 0;
}
// To recursively traverse a binary tree in a DFS fashion, we can start from the root and at every step, make two recursive calls one for the left and one for the right child.

// Here are the steps for our Binary Tree Path Sum problem:

// Start DFS with the root of the tree.
// If the current node is not a leaf node, do two things:
// Subtract the value of the current node from the given number to get a new sum => S = S - node.value
// Make two recursive calls for both the children of the current node with the new number calculated in the previous step.
// At every step, see if the current node being visited is a leaf node and if its value is equal to the given number ‘S’. If both these conditions are true, we have found the required root-to-leaf path, therefore return true.
// If the current node is a leaf but its value is not equal to the given number ‘S’, return false.