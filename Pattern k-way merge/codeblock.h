#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(){}
    
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* getNewNode (ListNode *p, int x){
    ListNode *temp = new ListNode();
    temp->val = x;
    temp->next = NULL;

    if(p == NULL){
        p = temp;
        return p;
    }
    ListNode *t = p;
    while(t->next != NULL){
        t = t->next;
    }

    t->next = temp;
    return p;
}
ListNode* input(){
    cout << "Enter the size of linked list : ";
    int n;
    cin >> n;
    ListNode *p = NULL;
    
    cout << "Enter val in nodes : ";
    for(int i =0; i < n; i++){
        int x;
        cin >> x;
        p = getNewNode(p, x);
    }
    return p;
}

void print(ListNode *p){
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
}