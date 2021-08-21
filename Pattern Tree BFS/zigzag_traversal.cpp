#include "codeblock.h"

vector<vector<int>> zigzag (TreeNode *root){
    vector<vector<int>> res;
    bool leftToRight = true;
    
    queue <TreeNode*> q;
    q.push(root);
    while(q.empty() == false){
        int levelSize = q.size();
        vector<int> temp(levelSize);
        for(int i =0; i < levelSize; i++){
            TreeNode *curr = q.front();
            q.pop();
            if(leftToRight){
                // In same order
                temp[i] = curr->val;
            }else{
                // In Reverse Order
                temp[(levelSize-1)-i] = curr->val;
            }
            
            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL)
                q.push(curr->right);
        }
        leftToRight = !leftToRight; // toggle the flag

        res.pb(temp);
    }
    return res;
}

int main(){
    TreeNode *root = getSampleTree();
    vector<vector<int>> res = zigzag (root);
    print(res);
    return 0;
}
// This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. The only additional step we have to keep in mind is to alternate the level order traversal,
//  which means that for every other level,
//  we will traverse similar to Reverse Level Order Traversal.