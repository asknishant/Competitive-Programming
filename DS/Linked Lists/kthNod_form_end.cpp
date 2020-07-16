#include <bits/stdc++.h>
using namespace std;


class node {
  public:
  int data;
  node* next;

  node(int data) {
    this->data = data;
  }
};

void insertAtHead(node* &head, int data) {
  node* n = new node(data);
  n->next = head;
  head = n;
}

void insertNodeAtEnd(node* head, int data) {
  node* n = new node(data);
  n->next = NULL;
  while(head->next!=NULL) {
    head = head->next;
  }
  head->next = n;
}

void insertAtMiddle(node* head, int data,int pos) {
  node* n = new node(data);
  int jumps = 0;
  while(jumps < pos-2) {
    head = head->next;
    jumps++;
  }
  n->next = head->next;
  head->next = n;
  
}

void print(node* head) {
  while(head!=NULL) {
    cout << head->data <<"-->";
    head = head->next;
  }
}

node* kthNodeFromEnd(node* head, int k) {
  node* fast = head;
  node* slow = head;

  while(k--) {
    fast = fast->next;
  }
  while(fast!=NULL) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}
int main() {
  node* head = NULL;
  insertAtHead(head, 4);
  insertAtHead(head, 5);
  insertAtHead(head, 7);
  insertAtHead(head, 2);
  insertAtMiddle(head, 7, 2);
  insertNodeAtEnd(head, 9);
  insertAtMiddle(head, 1, 3);
  print(head);

  int k;  
  cout << endl << "Find the value of kth node form end" << endl;
  cin >> k;
  cout << kthNodeFromEnd(head, k)->data;
  return 0;
}
