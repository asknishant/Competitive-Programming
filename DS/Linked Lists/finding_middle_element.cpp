#include <bits/stdc++.h> 
using namespace std;

class node {
  public :
    int data;
    node* next;
  
  node(int data) {
    this->data = data;
  }
};

void insertAtEnd(node* &head, int data) {
  node* n = new node(data);
  node* temp = head;
  n->next = NULL;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = n;
}

void insertAtHead(node* &head, int data) {
  node* n = new node(data);
  n->next = head;
  head = n;
}

void insertAtMiddle(node* &head, int data, int pos) {
  node* n = new node(data);
  node* temp = head;
  int jumps = 0;
  while(jumps < pos-1) {
    temp = temp->next;
    jumps++;
  }
  n->next = temp->next;
  temp->next = n;

}

void print(node* &head) {
  node* temp = head;
  while(temp != NULL) {
    cout << temp->data <<"-->";
    temp = temp->next;
  }
}

void reverseLL(node* &head) {
  node* curr = head;
  node* prev = NULL;
  node* n;

  while(curr != NULL) {
    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n; 
  }
}

node* revRec(node* head) {
  //Passing head by value.
  //Base Case
  if(head == NULL || head->next == NULL) {
    return head;
  }
  node* smallHead = revRec(head->next);
  node* curr = head;
  curr->next->next = curr;
  curr->next = NULL;
  return smallHead;
}

//Runner's technique to find the middle elment of the linked list.
node* findMiddle(node* head) {
  node* fast = head;
  node* slow = head;

  if(head==NULL or head->next ==NULL) {
    return head;
  }
  while(fast!=NULL and fast->next!=NULL) {
    fast = fast->next->next;
    slow = slow->next; 
  }

  return slow;
}

int main() {
  node* head = NULL;
  insertAtHead(head, 4);
  insertAtHead(head, 6);
  insertAtHead(head, 7);
  insertAtEnd(head, 9);
  insertAtMiddle(head, 1,3);
  print(head);
  cout << endl;
  head = revRec(head);
  print(head);
  cout << endl << findMiddle(head)->data;
  return 0;
}
