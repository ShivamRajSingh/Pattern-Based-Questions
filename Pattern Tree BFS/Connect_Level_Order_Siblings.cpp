#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x){
        val = x;
        left = right = next = NULL;
    }
};

 
 void helper(Node*& leftNode, Node*& rightNode) {
    if (!leftNode) {
        return;
    }
    leftNode->next = rightNode;
    helper(leftNode->left, leftNode->right);
    helper(leftNode->right, rightNode->left);
    helper(rightNode->left, rightNode->right);
}

Node* connectRecursive(Node* root) {
    if (!root) 
        helper(root->left, root->right);
    return root;
}

Node* connectIterative(Node* root) {
    if(root == NULL){
        return root;
    }

    queue <Node*> q;
    Node *curr, *prev;
    curr = prev = NULL;
    q.push(root);

    while(q.empty() == false){
        prev = NULL;
        int levelSize = q.size();
        
        for(int i =0; i < levelSize; i++){
            curr = q.front();
            q.pop();           
            if(prev != NULL){
                prev->next = curr;
            }
            prev = curr;

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }    
        }
        
    }
    return root;
}
int main(){
    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(2);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    // connectIterative(root);
    connectRecursive(root);
}