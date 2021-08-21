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

void print(Node *root){
    Node *temp = root;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

}

void connectNodes (Node *root){
    if(root == NULL){
        return;
    }

    queue <Node*> q;
    Node *curr, *prev;
    curr = prev = NULL;
    q.push(root);

    while(q.empty() == false){
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

int main(){
    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(2);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    connectNodes(root);
    print(root);
}