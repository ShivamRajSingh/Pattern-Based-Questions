#include "codeblock.h"

bool findPath (TreeNode *root , vector<int> seq, int i = 0){
    if(root == NULL){
       // Empty List 
        return false;
    }
    if(root->val != seq[i] && i > seq.size()){
        return false;
    }
    if(root->left == NULL && root->right == NULL && seq[i] == root->val){
        return true;
    }
    return findPath(root->left, seq, i+1) || findPath(root->right, seq, i+1);;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    cout << (findPath(root , vector<int>{1,0,7})) ? "True\n" : "False\n";
    cout << (findPath(root , vector<int>{1,6,5})) ? "True\n" : "False\n";
}