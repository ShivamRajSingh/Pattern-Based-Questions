#include "codeblock.h"

deque<vector<int>> reverseLevelOrder (TreeNode *root){
    deque<vector<int>> res = deque<vector<int>>();
    if(root == NULL){
        return res;
    }
    queue <TreeNode*> q;
    q.push(root);
    while(q.empty() == false){
        int level = q.size();
        vector<int> temp;
        for(int i =0; i < level; i++){
            TreeNode *curr = q.front();
            q.pop();
            temp.pb(curr->val);
            
            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL)
                q.push(curr->right);
        }
        res.push_front(temp);
    }
    return res;
}

int main(){
    TreeNode *root = getSampleTree();
    deque<vector<int>> res = reverseLevelOrder (root);
    for(auto i : res){
        for(auto j : i){
            cout << j <<" ";
        }
        cout << "\n";
    }
    return 0;
}