#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(): data(0), next(NULL) {}
    Node(int x): data(x), next(NULL) {}
    Node(int x, Node* next): data(x), next(next) {}
};

void printList(Node* node){
    if(node==NULL){
        cout << "Empty" << endl;
        return;
    }
    
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node* insertionSortList(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* temp = new Node(0);
    Node* curr = head;

    while(curr!=NULL){
        Node* pre = temp;
        Node* next = curr->next;

        while(pre->next != NULL && pre->next->data < curr->data)
            pre = pre->next;

        curr->next = pre->next;
        pre->next = curr;
        curr = next;
    }

    return temp->next;
}

int main(){
    int n; cin >> n;

    Node* head = NULL, *prev = NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        Node* curr = new Node(x);
        if(i==0) head = prev = curr;
        prev->next = curr;
        prev = curr;
    }

    head = insertionSortList(head);

    printList(head);

    return 0;
}