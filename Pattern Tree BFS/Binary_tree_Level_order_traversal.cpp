#include "codeblock.h"

vector<vector<int>> levelOrder (TreeNode *root){
    queue <TreeNode*> q;
    vector<vector<int>> res;
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
// Since we need to traverse all nodes of each level before moving onto the next level, we can use the Breadth First Search (BFS) technique to solve this problem.

// We can use a Queue to efficiently traverse in BFS fashion. Here are the steps of our algorithm:

// Start by pushing the root node to the queue.
// Keep iterating until the queue is empty.
// In each iteration, first count the elements in the queue (let’s call it levelSize). We will have these many nodes in the current level.
// Next, remove levelSize nodes from the queue and push their value in an array to represent the current level.
// After removing each node from the queue, insert both of its children into the queue.
// If the queue is not empty, repeat from step 3 for the next level.