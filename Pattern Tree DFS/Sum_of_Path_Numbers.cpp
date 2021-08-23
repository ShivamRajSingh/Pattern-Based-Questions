#include "codeblock.h"

int helper (TreeNode *root , int sum){
    if(root == NULL)
        return 0;
    
    sum = 10*sum + root->val;

    if(root->left == NULL && root->right == NULL){
        return sum;
    }

    return helper(root->left ,sum) + helper(root->right,sum);

}


int sumPath( TreeNode *root){
    return helper(root, 0);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(9);
    cout << sumPath(root);

    return 0;
}