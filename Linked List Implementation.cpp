#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int n){
        data=n;
        next=NULL;
    }
};

void insertAtbeg(Node* &head, int n){
    Node *temp = new Node(n);
    temp->next = head;
    head = temp;
}

void insertAtPos(Node* &head, int d, int pos){
    Node* temp = new Node(d);

    if(head == NULL){
        head = temp;
        return;
    }
    
    Node* n = head;
    pos--;
    while(--pos){
        n = n->next;
    }
    Node* m = n->next;
    n->next = temp;
    temp->next = m;
}

void insertAtEnd(Node* &head, int n){
    Node* t = new Node(n);
    
    if(head == NULL){
        head = t;
        return;
    }
    
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = t;
    t->next = NULL;
}

void insertAfterNode(Node* &head, Node* node, int n){
    Node* temp = new Node(n);
    if(node == NULL){
        head = temp;
    }
    Node* t = node->next;
    node->next = temp;
    temp->next = t;
}

int deleteFirstNode(Node* &head){
    if(head == NULL){
        cout<<"\nLinked List is Empty.\n";
        return -1;
    }
    Node* temp = head;
    head = head->next;
    return temp->data;
}

int deleteNodeAt(Node* &head, int pos){
    if(head == NULL){
        cout<<"\nLinked List is Empty.\n";
        return -1;
    }
    Node* temp = head;
    pos--;
    while(--pos){
        temp=temp->next;
    }
    Node* t = temp->next;
    temp->next = t->next;
    return t->data;
}

int deleteLastNode(Node* &head){
    if(head == NULL){
        cout<<"\nLinked List is Empty.\n";
        return -1;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* t = temp->next;
    temp->next = NULL;
    return t->data;
}

void search(Node* head, int key){
    Node* temp = head;
     while(temp!=NULL){
        if(temp->data == key){
            cout<<key<<" is present in LL.\n";
            return;
        }
        temp = temp->next;
     }
     cout<<key<<" is NOT present in LL.\n";
}

void display(Node* head){
    if(head == NULL) cout<<"Empty Linked List!!";
    else {
        Node *temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<"\n";
    }
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* reverseRec(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newNode = reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;

    return newNode;
}

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reOrder(Node* &head){
    Node* temp = head;
    Node* first = temp; 
    Node* mid = middle(temp);

    while(temp!=mid){
        temp = temp->next;
    } Node* sec = temp->next;
    temp->next = NULL;
    Node* second = reverse(sec);
    while(second!=NULL){
        Node* t = first->next;
        first->next = second;
        first = t;
        t = second->next;
        second->next = first;
        second = t;
    }
}


int main(){   
    Node* head=NULL;
    insertAtbeg(head, 6);
    insertAtbeg(head, 5);    
    insertAtbeg(head, 4);
    insertAtbeg(head, 3);
    insertAtbeg(head, 2);
    insertAtbeg(head, 1);
    display(head);
    cout<<"\n";
    reOrder(head);
    display(head);
    return 0;
}