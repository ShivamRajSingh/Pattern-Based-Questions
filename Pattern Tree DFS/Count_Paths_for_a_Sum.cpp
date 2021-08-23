#include "codeblock.h"

int helper (TreeNode *root, int sum , vector<int> &currentPath){
    if(root == NULL){
        return 0;
    }
    
    currentPath.push_back(root->val);
    int pathCount = 0, pathSum =0;
    for(auto itr = currentPath.rbegin(); itr != currentPath.rend(); itr++){
        pathSum += *itr;
        if(pathSum == sum){
            pathCount++;
        }
    }
    pathCount += helper(root->left , sum , currentPath);
    pathCount += helper(root->right , sum , currentPath);

    currentPath.pop_back();

    return pathCount;
}


int countPaths (TreeNode *root , int sum){
    vector<int> currentPath;
    return helper(root, sum , currentPath);
}

int main()
{
    TreeNode *root = getSampleTree();
    int sum;
    cout << "Enter the sum you want to find : ";
    cin >> sum;
    cout << "No. of paths : " << countPaths(root , sum);
    return 0;
}