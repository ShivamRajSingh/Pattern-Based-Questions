#include "codeblock.h"

vector<vector<int>> levelOrder (TreeNode *root){
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
    vector<vector<int>> res = levelOrder (root);
    print(res);
    return 0;
}