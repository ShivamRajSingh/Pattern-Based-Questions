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
// This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach. But there will be four differences:

// We will keep track of the current path in a list which will be passed to every recursive call.

// Whenever we traverse a node we will do two things:

// Add the current node to the current path.
// As we added a new node to the current path, we should find the sums of all sub-paths ending at the current node. If the sum of any sub-path is equal to ‘S’ we will increment our path count.
// We will traverse all paths and will not stop processing after finding the first path.

// Remove the current node from the current path before returning from the function. This is needed to Backtrack while we are going up the recursive call stack to process other paths.



// Time Complexity : Worst Case : O(n^2)
                    // Best Case : O(nlogn)
// Space Complexity : O(n)