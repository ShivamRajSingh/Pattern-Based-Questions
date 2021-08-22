#include "codeblock.h"

struct compare{
    bool operator() (const ListNode *x, const ListNode *y){
        return x->val > y->val;
    }
};

ListNode* merge (vector <ListNode*> lists){
    priority_queue<ListNode* ,vector<ListNode*> , compare> minHeap;

    for(auto root : lists){
        if(root != NULL)
            minHeap.push(root);
    }        
    
    ListNode *head, *tail;
    head = tail = nullptr;

    while(minHeap.empty() == false){
        ListNode *curr = minHeap.top();
        minHeap.pop();
        if(head == NULL){
            head = tail = curr;
        }else{
            tail->next = curr;
            tail = tail->next;
        }
        if(curr->next != NULL){
            minHeap.push(curr->next);
        }
    }
    return head;
}
int main()
{
    ListNode *l1,*l2,*l3, *l4;
    l1 = input();
    l2 = input();
    l3 = input();
    vector<ListNode*> inp;
    inp.push_back(l1);
    inp.push_back(l2);
    inp.push_back(l3);
    l4 = merge(inp);
    print (l4);
    return 0;
}