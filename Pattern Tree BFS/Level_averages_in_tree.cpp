#include "codeblock.h"

vector<double> levelAverages (TreeNode *root){
    if(root == NULL){
        return {};
    }
    queue <TreeNode*> q;
    vector<double> res;
    q.push(root);
    while(q.empty() == false){
        int levelSize = q.size();
        double levelSum = 0;
        for(int i =0; i < levelSize; i++){
            TreeNode *curr = q.front();
            q.pop();
            levelSum += curr->val;
            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL)
                q.push(curr->right);
        }
        res.pb(levelSum / levelSize);
    }
    return res;
}

int main(){
    TreeNode *root = getSampleTree();
    vector<double> res = levelAverages (root);
    for(auto i : res){
        cout << i << " ";
    }
    return 0;
}
// This problem follows the Binary Tree Level Order Traversal pattern.
//  We can follow the same BFS approach.
//  The only difference will be that instead of keeping track of all nodes of a level, we will only track the running sum of the values of all nodes in each level.
//  In the end, we will append the average of the current level to the result array.