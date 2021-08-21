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