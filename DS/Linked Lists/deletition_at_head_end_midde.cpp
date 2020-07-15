#include <bits/stdc++.h>
using namespace std;


class node {
  public:
    int data;
    node* next;
};

void insertNodeAtHead(node* &head, int data) {
  //Here we are passing head with reference.As the scope of head is main() we want to get it changed everytime
  //So that we can update value of head so that whenever we want to add a new node we use this head(which is passed by reference not by value).
  node* n = new node;
  n->data = data; //Or We can use (*n).data = data.
  n->next = head;
  head = n;
}

void print(node* head) {
  //Here head is passed by value not by reference that means actual value of head does not change.
  //temp is not necessary but for better understanding we have created it. 
  node* temp;
  temp = head;

  while(temp != NULL) {
    cout << temp->data << "-->";
    temp = temp->next;
  }
}
int lengthLL(node* head) {
  //Here head is passed by value not by reference.
  int len = 0;
  while(head != NULL) {
    head = head->next;
    len++;
  }
  return len;
}

void insertAtTail(node* &head, int data) {
  while(head==NULL) {
    head = new node;
    return;
  }
  node* tail = head;
  while(tail->next!=NULL) {
    tail = tail->next;
  }
  node* n = new node;
  n->data = data;
  n->next = NULL;
  tail->next = n;
}

void insertInMidde(node* & head, int pos, int data) {
  if(head == NULL || pos == 0) {
    insertNodeAtHead(head, data);
  } else if(pos > lengthLL(head)) {
    insertAtTail(head,data);
  }
  else {
    int jump = 0;
    node* temp = head;
    while(jump < pos-1) {
      temp = temp ->next;
      jump++;
    }
    node* n = new node;
    n->data = data;
    n->next = temp->next;
    temp->next = n;

  }
}
void deleteTailNode(node* &head) {
  node* prev = head;
  node* temp = head;
  while(temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  delete temp;
}

void deleteFrontNode(node* &head) {
  node* temp = head;
  head = head->next;
  delete temp;
}

void deleteAtMiddle(node* &head, int pos) {
  int jump = 0;
  node* temp = head;
  node* prev = head;
  while(jump < pos-1) {
    prev = temp;
    temp = temp->next;
    jump++;
  }
  prev->next = temp->next;
  delete temp;
}
int main() {
  node* head = NULL;

  insertNodeAtHead(head, 2);
  insertNodeAtHead(head, 3);
  insertNodeAtHead(head, 4);
  insertAtTail(head, 6);
  insertInMidde(head, 2, 7);

  //deleteTailNode(head);
  //deleteFrontNode(head);
  deleteAtMiddle(head, 3);
  print(head);

}
